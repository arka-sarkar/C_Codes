# CLI Arguments & File I/O in C — Quick Cheat Sheet

> See [cli_fileio_demo.c](file:///home/runcandel/ESC111_112/2_t7/cli_fileio_demo.c) for a complete, runnable program demonstrating every pattern below.

---

## 1. Command-Line Arguments (`argc` & `argv`)

Use `int main(int argc, char *argv[])` when your program takes inputs directly from the terminal command line.

Suppose you run:
```bash
./program input.csv 10 -v
```
Inside `main`:
- `argc` = `4` (always $\ge 1$, includes the program name)
- `argv[0]` = `"./program"`
- `argv[1]` = `"input.csv"`
- `argv[2]` = `"10"` *(always a string `char *`, NOT an integer!)*
- `argv[3]` = `"-v"`
- `argv[4]` = `NULL` (`argv[argc]` is always `NULL`)

### Essential CLI Patterns

```c
// 1. Always check argc BEFORE accessing argv[1], argv[2], ...
if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <count>\n", argv[0]);
    return 1;
}

const char *filename = argv[1];

// 2. Converting CLI strings to numbers
int n_quick = atoi(argv[2]);      // Simple, but returns 0 on "abc"
double d_quick = atof(argv[2]);

// Safe integer conversion (detects invalid text like "12abc"):
char *end;
long n_safe = strtol(argv[2], &end, 10);
if (*argv[2] == '\0' || *end != '\0') {
    fprintf(stderr, "Error: '%s' is not a valid integer\n", argv[2]);
    return 1;
}

// 3. Checking flags (use strcmp, NEVER ==)
int verbose = 0;
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
        verbose = 1;
    }
}
```

---

## 2. Opening & Closing Files (`fopen`, `fclose`)

```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) {
    perror("data.txt");   // Prints OS error reason to stderr (e.g. "data.txt: No such file or directory")
    return 1;
}
/* ... read or write ... */
fclose(fp);               // Always close! Flushes output buffers and frees OS file handle.
```

### File Open Modes

| Mode | Meaning | If File Exists | If File Missing |
| :--- | :--- | :--- | :--- |
| `"r"` | Read text | Opens at start | Returns `NULL` (error) |
| `"w"` | Write text | **WIPES / TRUNCATES to 0 bytes!** | Creates new file |
| `"a"` | Append text | Preserves content; writes at end | Creates new file |
| `"r+"` | Read & Write text | Opens at start (keeps data) | Returns `NULL` |
| `"w+"` | Read & Write text | **WIPES / TRUNCATES to 0 bytes!** | Creates new file |
| `"rb"` / `"wb"` / `"ab"` | Binary mode | Same as `"r"` / `"w"` / `"a"`, without newline translation | Same as above |

---

## 3. Text File Reading & Writing Patterns

### Writing Text (`fprintf`, `fputs`)
```c
FILE *out = fopen("report.txt", "w");
if (out == NULL) { perror("report.txt"); return 1; }
fprintf(out, "Score: %d (%.2f%%)\n", 45, 90.0);
fclose(out);
```

### Pattern A: Reading Line-by-Line (`fgets` — Safest)
```c
char line[256];
while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, "\r\n")] = '\0';   // Strip trailing \n or \r\n safely
    printf("Read: %s\n", line);
}
```

### Pattern B: Reading CSV with `fgets` + `strtok`
```c
char line[256];
fgets(line, sizeof(line), fp); // Optional: skip CSV header row

while (fgets(line, sizeof(line), fp) != NULL) {
    char *id_str   = strtok(line, ",\r\n");   // First call passes `line`
    char *name     = strtok(NULL, ",\r\n");   // Next calls pass NULL
    char *price_str = strtok(NULL, ",\r\n");
    if (id_str && name && price_str) {
        int id = atoi(id_str);
        int price = atoi(price_str);
        // Use id, name, price...
    }
}
```
> **Note:** `strtok` modifies `line` in-place and merges consecutive delimiters (`"a,,b"` skips the empty field).

### Pattern C: Formatted Reading (`fscanf`)
```c
int id;
char category[32];
int price;
// %31[^,] reads up to 31 characters until a comma (stops buffer overflow!)
while (fscanf(fp, "%d,%31[^,],%d", &id, category, &price) == 3) {
    // Process record...
}
```

### Pattern D: Character-by-Character (`fgetc`)
```c
int ch;  // MUST be int (not char!) so EOF (-1) is never confused with byte 255
while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
}
```

---

## 4. Binary File I/O & Random Access

Best when storing raw `struct`s or arrays without formatting/parsing text.

```c
typedef struct {
    int id;
    double val;
} Record;

// Writing binary records
Record arr[2] = {{1, 12.5}, {2, 99.0}};
FILE *wb = fopen("data.bin", "wb");
fwrite(arr, sizeof(Record), 2, wb);
fclose(wb);

// Reading binary records sequentially
Record r;
FILE *rb = fopen("data.bin", "rb");
while (fread(&r, sizeof(Record), 1, rb) == 1) {
    printf("id=%d val=%.2f\n", r.id, r.val);
}

// Random access: jump straight to record index `k` (0-indexed)
fseek(rb, k * (long)sizeof(Record), SEEK_SET);
fread(&r, sizeof(Record), 1, rb);

// Finding total file size in bytes:
fseek(rb, 0, SEEK_END);
long bytes = ftell(rb);
rewind(rb);  // Jump back to byte 0
fclose(rb);
```

| `fseek(fp, offset, origin)` Origin | Meaning |
| :--- | :--- |
| `SEEK_SET` | From start of file (byte `0`) |
| `SEEK_CUR` | From current cursor position |
| `SEEK_END` | From end of file |

---

## 5. Standard Streams (`stdin`, `stdout`, `stderr`)

Every C program starts with 3 already-opened `FILE *` streams (do NOT `fopen`/`fclose` them):
- `stdin`: Standard input (`scanf(...)` is shorthand for `fscanf(stdin, ...)`).
- `stdout`: Standard output (`printf(...)` is shorthand for `fprintf(stdout, ...)`).
- `stderr`: Standard error (`fprintf(stderr, ...)`). Always use `stderr` for error/usage messages so they still appear on screen even if output is redirected via `./prog > out.txt`.

---

## 6. Common Mistakes Checklist

1. **Using `while (!feof(fp))`**: **Bug!** `feof()` only becomes true *after* a read attempts to go past the end, causing the last line/record to process twice. Always loop on `fgets(...) != NULL`, `fscanf(...) == expected_count`, or `fread(...) == 1`.
2. **Accessing `argv[1]` without checking `argc`**: Causes Segmentation Fault if user runs `./prog` with no args.
3. **Comparing CLI strings with `==`**: `if (argv[1] == "-v")` compares memory pointers! Always use `strcmp(argv[1], "-v") == 0`.
4. **Using `char` for `fgetc()`**: `EOF` is `-1`; `char` may be unsigned on some platforms. Always declare `int ch;`.
5. **Forgetting `"w"` wipes existing files**: Back up important inputs before testing `"w"` mode, and check you didn't swap input and output arguments!
6. **Forgetting `fclose(fp)`**: Can lose buffered writes (especially before reading back the same file in the same program).

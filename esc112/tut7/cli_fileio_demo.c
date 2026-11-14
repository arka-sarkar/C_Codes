/*
 * ============================================================================
 * ESC 112: CLI Arguments (argc/argv) & File I/O — Complete Demo & Cheat Sheet
 * ============================================================================
 *
 * Compile:
 *   gcc -Wall -Wextra -Werror cli_fileio_demo.c -o demo
 *
 * Try running with different arguments:
 *   ./demo
 *   ./demo Alice 42 3.14 -v
 *   ./demo --keep          (keeps generated sample files on disk to inspect)
 *   ./demo --help          (prints quick usage summary)
 * ============================================================================
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char tag[16];
    double value;
} SensorLog;

/* ============================================================================
 * 1. COMMAND-LINE ARGUMENTS (argc & argv)
 * ============================================================================
 * Key Rules:
 *   - argc ("argument count"): always >= 1 (argv[0] is the program name).
 *   - argv ("argument vector"): array of C-strings (char *), NULL-terminated
 *     at argv[argc] == NULL.
 *   - ALL command-line arguments arrive as strings (char *). To use them as
 *     numbers, convert them with strtol / strtod (safe) or atoi / atof (quick).
 *   - Always validate argc BEFORE accessing argv[1], argv[2], etc., to avoid
 *     segfaults / out-of-bounds reads!
 */
static void print_usage(const char *prog_name) {
    printf("Usage: %s [any_args...] [-v | --verbose] [--keep] [-h | --help]\n", prog_name);
    printf("  -v, --verbose : Print extra explanatory notes\n");
    printf("  --keep        : Keep generated demo files instead of deleting them\n");
    printf("  -h, --help    : Show this help message and exit\n");
}

static int demo_cli(int argc, char *argv[], int *verbose, int *keep_files) {
    printf("================================================================\n");
    printf("PART 1: COMMAND-LINE ARGUMENTS (argc & argv)\n");
    printf("================================================================\n");
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = \"%s\"", i, argv[i]);
        if (i == 0) {
            printf("  <-- (program invocation name)");
        }
        printf("\n");

        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printf("\n");
            print_usage(argv[0]);
            return 1; /* signal caller to stop cleanly */
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            *verbose = 1;
        } else if (strcmp(argv[i], "--keep") == 0) {
            *keep_files = 1;
        }
    }
    printf("  argv[%d] = NULL (guaranteed sentinel by C standard)\n", argc);

    /* Demonstrate classifying & converting user arguments (argv[1..argc-1]) */
    if (argc == 1) {
        printf("\nTip: Run `%s Alice 42 -v` to see argument parsing in action!\n", argv[0]);
    } else {
        printf("\nInspecting user-supplied arguments (argv[1] .. argv[%d]):\n", argc - 1);
        for (int i = 1; i < argc; i++) {
            const char *arg = argv[i];
            if (arg[0] == '-') {
                printf("  Arg %d (\"%s\") -> detected as a FLAG/OPTION\n", i, arg);
                continue;
            }

            /* Safe integer parsing using strtol (preferred over atoi) */
            char *endptr = NULL;
            errno = 0;
            long val = strtol(arg, &endptr, 10);
            if (*arg != '\0' && *endptr == '\0' && errno == 0) {
                printf("  Arg %d (\"%s\") -> valid INTEGER: %ld\n", i, arg, val);
                continue;
            }

            /* Safe floating-point parsing using strtod (preferred over atof) */
            errno = 0;
            double dval = strtod(arg, &endptr);
            if (*arg != '\0' && *endptr == '\0' && errno == 0) {
                printf("  Arg %d (\"%s\") -> valid DOUBLE:  %.4f\n", i, arg, dval);
                continue;
            }

            printf("  Arg %d (\"%s\") -> plain STRING\n", i, arg);
        }
    }

    if (*verbose) {
        printf("\n[Verbose Note] Typical fixed-argument check pattern:\n");
        printf("  if (argc != 3) {\n");
        printf("      fprintf(stderr, \"Usage: %%s <in> <out>\\n\", argv[0]);\n");
        printf("      return 1;\n");
        printf("  }\n");
    }
    printf("\n");
    return 0;
}

/* ============================================================================
 * 2. TEXT FILE I/O: "w" (Write), "a" (Append), "r" (Read)
 * ============================================================================
 * Mode Cheat Sheet:
 *   "r"  -> Read only. File MUST exist (returns NULL otherwise).
 *   "w"  -> Write only. Creates if missing; OVERWRITES (truncates to 0) if exists!
 *   "a"  -> Append only. Creates if missing; writes strictly at end of file.
 *   "r+" -> Read + Write (must exist). "w+" -> Read + Write (truncates).
 *
 * Essential Habits:
 *   1. ALWAYS check `if (fp == NULL)` immediately after `fopen`.
 *   2. Use `perror("context")` or `strerror(errno)` to print the OS reason.
 *   3. ALWAYS call `fclose(fp)` when done so buffered writes flush to disk.
 *   4. NEVER write `while (!feof(fp))` — check the return value of `fgets`,
 *      `fscanf`, or `fgetc` directly instead!
 */
static void demo_text_file_io(int verbose, int keep_files) {
    const char *filename = "demo_notes.txt";

    printf("================================================================\n");
    printf("PART 2: TEXT FILE I/O (Write, Append, Read)\n");
    printf("================================================================\n");

    /* --- A. Writing with "w" --- */
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen for write failed");
        return;
    }
    fprintf(fp, "Line 1: Welcome to ESC 112!\n");
    fprintf(fp, "Line 2: File I/O uses FILE* streams.\n");
    fclose(fp);
    printf("[1] Wrote 2 lines to '%s' using mode \"w\".\n", filename);

    /* --- B. Appending with "a" --- */
    fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("fopen for append failed");
        return;
    }
    fprintf(fp, "Line 3: Appended safely with mode \"a\".\n");
    fclose(fp);
    printf("[2] Appended 1 line to '%s' using mode \"a\".\n", filename);

    /* --- C. Reading line-by-line with fgets() --- */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen for read failed");
        return;
    }
    printf("[3] Reading line-by-line with fgets():\n");
    char buffer[256];
    int line_no = 1;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        /* Idiomatic safe newline removal (handles both \n and \r\n) */
        buffer[strcspn(buffer, "\r\n")] = '\0';
        printf("    [%d] %s\n", line_no++, buffer);
    }

    /* --- D. Rewinding & reading char-by-char with fgetc() --- */
    rewind(fp); /* Resets file position cursor back to byte 0 */
    int ch;     /* MUST be int (NOT char) so EOF (-1) is distinguishable */
    int char_count = 0;
    while ((ch = fgetc(fp)) != EOF) {
        char_count++;
    }
    printf("[4] Rewound stream and counted %d characters with fgetc().\n", char_count);
    fclose(fp);

    if (verbose) {
        printf("[Verbose Note] Why `int ch`? Because fgetc() returns 0..255 or EOF (-1).\n");
        printf("               Storing it in `char` can break EOF detection.\n");
    }

    if (!keep_files) {
        remove(filename);
    }
    printf("\n");
}

/* ============================================================================
 * 3. CSV PARSING: Method A (fgets + strtok) vs Method B (fscanf)
 * ============================================================================
 * Note on strtok:
 *   - First call passes the string: `strtok(line, ",\r\n")`
 *   - Subsequent calls pass NULL:   `strtok(NULL, ",\r\n")`
 *   - Warning: `strtok` MODIFIES the input buffer in-place by inserting '\0'!
 *   - Warning: `strtok` treats consecutive delimiters (e.g. "101,,80") as one,
 *     so it skips empty fields.
 */
static void demo_csv_parsing(int verbose, int keep_files) {
    const char *csv_file = "demo_students.csv";

    printf("================================================================\n");
    printf("PART 3: CSV PARSING (strtok vs fscanf)\n");
    printf("================================================================\n");

    FILE *fp = fopen(csv_file, "w");
    if (fp == NULL) {
        perror("Failed to create CSV");
        return;
    }
    fprintf(fp, "RollNo,Name,Score\n");
    fprintf(fp, "101,Aarav,88.5\n");
    fprintf(fp, "102,Bhavna,94.0\n");
    fprintf(fp, "103,Chirag,76.5\n");
    fclose(fp);

    /* --- Method A: fgets + strtok --- */
    fp = fopen(csv_file, "r");
    if (fp == NULL) {
        perror("Failed to open CSV for strtok");
        return;
    }
    char line[256];
    if (fgets(line, sizeof(line), fp) != NULL) {
        /* Skipped header line */
    }
    printf("[Method A] Parsing via fgets() + strtok():\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *tok_roll = strtok(line, ",\r\n");
        char *tok_name = strtok(NULL, ",\r\n");
        char *tok_score = strtok(NULL, ",\r\n");
        if (tok_roll && tok_name && tok_score) {
            int roll = atoi(tok_roll);
            double score = atof(tok_score);
            printf("    Roll=%d | Name=%-8s | Score=%.1f\n", roll, tok_name, score);
        }
    }
    fclose(fp);

    /* --- Method B: fgets (skip header) + fscanf with scanset --- */
    fp = fopen(csv_file, "r");
    if (fp == NULL) {
        perror("Failed to open CSV for fscanf");
        return;
    }
    if (fgets(line, sizeof(line), fp) != NULL) {
        /* Skipped header line */
    }
    printf("[Method B] Parsing via fscanf(\"%%d,%%49[^,],%%lf\"):\n");
    int roll;
    char name[50];
    double score;
    /* %49[^,] reads up to 49 chars until a comma is reached (prevents overflow!) */
    while (fscanf(fp, "%d,%49[^,],%lf", &roll, name, &score) == 3) {
        printf("    Roll=%d | Name=%-8s | Score=%.1f\n", roll, name, score);
    }
    fclose(fp);

    if (verbose) {
        printf("[Verbose Note] Notice `%%49[^,]` in fscanf: standard `%%s` stops at\n");
        printf("               whitespace, NOT commas! `[^,]` tells scanf to read\n");
        printf("               everything except a comma, capped at 49 chars.\n");
    }

    if (!keep_files) {
        remove(csv_file);
    }
    printf("\n");
}

/* ============================================================================
 * 4. BINARY FILE I/O & RANDOM ACCESS ("wb", "rb", fwrite, fread, fseek, ftell)
 * ============================================================================
 * Why Binary Mode ("rb" / "wb")?
 *   - Writes exact raw bytes of structs/arrays without formatting to text.
 *   - Fixed-size records allow O(1) jumping to record `k` via fseek()!
 *   - Note: Binary files are NOT human-readable with `cat` and depend on CPU
 *     endianness and struct padding.
 */
static void demo_binary_file_io(int verbose, int keep_files) {
    const char *bin_file = "demo_logs.bin";

    printf("================================================================\n");
    printf("PART 4: BINARY FILE I/O & RANDOM ACCESS (fwrite, fread, fseek)\n");
    printf("================================================================\n");

    SensorLog outgoing[3] = {
        {1, "TEMP_A", 24.5},
        {2, "HUMID_B", 61.2},
        {3, "PRESS_C", 101.3}
    };

    /* Write array of 3 structs in one call */
    FILE *fp = fopen(bin_file, "wb");
    if (fp == NULL) {
        perror("fopen wb failed");
        return;
    }
    size_t written = fwrite(outgoing, sizeof(SensorLog), 3, fp);
    fclose(fp);
    printf("[1] Wrote %zu binary records (%zu bytes each) to '%s'.\n",
           written, sizeof(SensorLog), bin_file);

    /* Read back, measure file size, and demonstrate random access */
    fp = fopen(bin_file, "rb");
    if (fp == NULL) {
        perror("fopen rb failed");
        return;
    }

    /* Jump to end to measure file size */
    fseek(fp, 0, SEEK_END);
    long file_bytes = ftell(fp);
    long total_records = file_bytes / (long)sizeof(SensorLog);
    printf("[2] File size via fseek(SEEK_END) + ftell(): %ld bytes (%ld records).\n",
           file_bytes, total_records);

    /* Random access: jump directly to record index 2 (3rd record) */
    SensorLog single;
    long target_idx = 2;
    fseek(fp, target_idx * (long)sizeof(SensorLog), SEEK_SET);
    if (fread(&single, sizeof(SensorLog), 1, fp) == 1) {
        printf("[3] Random access to record[%ld]: ID=%d, Tag=%s, Value=%.1f\n",
               target_idx, single.id, single.tag, single.value);
    }

    /* Sequential read of all records from start */
    rewind(fp);
    printf("[4] Sequential read of all binary records:\n");
    while (fread(&single, sizeof(SensorLog), 1, fp) == 1) {
        printf("    ID=%d | Tag=%-8s | Value=%.1f\n",
               single.id, single.tag, single.value);
    }
    fclose(fp);

    if (verbose) {
        printf("[Verbose Note] Always match fwrite/fread element count check:\n");
        printf("               `while (fread(&item, sizeof(T), 1, fp) == 1)`\n");
    }

    if (!keep_files) {
        remove(bin_file);
    }
    printf("\n");
}

/* ============================================================================
 * 5. STANDARD STREAMS: stdin, stdout, stderr
 * ============================================================================
 *   - stdout: Normal program output (buffered; redirected by `> out.txt`).
 *   - stderr: Error/diagnostic output (unbuffered; NOT captured by `> out.txt`,
 *             so errors stay visible on screen even during redirection!).
 */
static void demo_std_streams(void) {
    printf("================================================================\n");
    printf("PART 5: STANDARD STREAMS (stdout vs stderr)\n");
    printf("================================================================\n");
    fprintf(stdout, "This went to stdout (normal output; redirectable with `>`).\n");
    fprintf(stderr, "This went to stderr (errors/usage; stays visible if stdout is redirected).\n");
}

int main(int argc, char *argv[]) {
    int verbose = 0;
    int keep_files = 0;

    if (demo_cli(argc, argv, &verbose, &keep_files) != 0) {
        return 0; /* --help requested */
    }

    demo_text_file_io(verbose, keep_files);
    demo_csv_parsing(verbose, keep_files);
    demo_binary_file_io(verbose, keep_files);
    demo_std_streams();

    if (keep_files) {
        printf("\n[--keep active] Created files kept in current directory:\n");
        printf("  demo_notes.txt, demo_students.csv, demo_logs.bin\n");
    }

    return 0;
}

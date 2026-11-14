#include<stdio.h>
#include<ctype.h>
#include<string.h>

void count_cases(const char *s, int* lower, int *upper) {
    *lower = *upper = 0;
    while (*s) {
        if(isupper(*s)) (*upper)++;
        else if(islower(*s)) (*lower)++;
        s++;
    }
}

void toggle_case(char *s) {
    while (*s) {
        if(isupper(*s)) *s = tolower(*s);
        else if(islower(*s)) *s = toupper(*s);
        s++;
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    char words[n][31];

    for (int i = 0; i < n; i++) scanf(" %29s", words[i]);

    int upper, lower, best = 0;

    for (int i = 0; i < n; i++) {
        count_cases(words[i], &lower, &upper);
        toggle_case(words[i]);
        printf("%s %d %d ", words[i], upper, lower);

        if(strlen(words[i]) > strlen(words[best])) best = i;
    }
    printf("%s\n", words[best]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#ifndef GOOGLE_TEST
void print_table(const char *s, size_t len, int table[][len]) {
    printf("%s", "\033[38;5;87m");
    for (size_t i = 0; i < len; ++i) {
        printf("%c ", s[i]);
    }
    printf("\033[m\n");

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 0; j < len; ++j) {
            const char *s = "F";
            if (table[i][j] == 1) {
                s = "\033[1;31mT\033[m";
            }
            printf("%s ", s);
        }
        printf("\n");
    }
}
#endif

char *longestPalindrome(char *s) {
    size_t len = strlen(s);
    if (len <= 1) {
        return s;
    }
    size_t start = 0, max = 0;
    int table[len][len];
    bzero(&table, sizeof(table));
    for (size_t i = 0; i < len; ++i) {
        table[i][i] = 1;
        for (size_t j = 0; j < i; ++j) {
            table[j][i] = s[i] == s[j] && ((i - j) == 1 || table[j + 1][i - 1]);
            if (table[j][i] == 1 && (i - j) > max) {
                start = j;
                max = i - j;
            }
        }
    }

#ifndef GOOGLE_TEST
    print_table(s, len, table);
#endif

    char *longest = (char*)calloc((len + 1), sizeof(char));
    strncpy(longest, s + start, max + 1);
    return longest;
}

#ifndef GOOGLE_TEST
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s string\n", argv[0]);
        exit(-1);
    }
    char *longest = longestPalindrome(argv[1]);
    //    char *longest = longestPalindrome("");
    printf("\nlongest: %s\n", longest);
    return 0;
}
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline const char *digit_to_code(const char digit) {
    static const char *tables[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return tables[digit - '2'];
}

char **output = NULL;
void backtrack(char **result, char *combination, int index, const char *next_digits) {
    if (next_digits[0]) {
        const char *code = digit_to_code(next_digits[0]);
        for (size_t i = 0; i < strlen(code); ++i) {
            combination[index] = code[i];
            backtrack(result, combination, index + 1, next_digits + 1);
        }
    } else {
        strcpy(*output++, combination);
    }
}

char ** letterCombinations(char * digits, int* returnSize) {
    int totals = 1;
    size_t groups = strlen(digits);
    if (groups == 0) {
        *returnSize = 0;
        return (char**)calloc(1, sizeof(char**));
    }
    for (size_t i = 0; i < groups; ++i) {
        totals *= strlen(digit_to_code(digits[i]));
    }
    *returnSize = totals;
    char **result = (char**)calloc(totals, sizeof(char*));
    for (int i = 0; i < totals; ++i) {
        result[i] = (char*)calloc(groups + 1, sizeof(char));
    }
    char *temp = (char*)calloc(groups + 1, sizeof(char));
    output = result;
    backtrack(result, temp, 0, digits);
    free(temp);
    return result;
}

#ifndef GOOGLE_TEST
int main() {
    int returnSize = 0;
    char **result = letterCombinations("23", &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}
#endif

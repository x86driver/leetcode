#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *results = NULL;
    int carry = 0;
    results = (int*)calloc(digitsSize, sizeof(int));
    memcpy(results, digits, digitsSize * sizeof(int));
    for (int i = digitsSize - 1; i >= 0; --i) {
        ++results[i];
        if (results[i] >= 10) {
            carry = 1;
            results[i] = 0;
        } else {
            carry = 0;
            break;
        }
    }
    if (carry) {
        int *tmp = (int*)malloc((digitsSize + 1) * sizeof(int));
        memcpy(tmp + 1, results, digitsSize * sizeof(int));
        tmp[0] = carry;
        free(results);
        results = tmp;
    }
    *returnSize = digitsSize + carry;
    return results;
}

#ifdef _MAIN_
int main() {
    int digits[] = {9, 9, 9};
    const int N = sizeof(digits)/sizeof(int);
    int *results = NULL;
    int returnSize = 0;
    results = plusOne(digits, N, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", results[i]);
    }
    printf("\n");
    free(results);
    return 0;
}
#endif

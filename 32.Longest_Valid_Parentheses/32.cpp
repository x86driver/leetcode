#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int longestValidParentheses(char * s){
    int len = (int)strlen(s);
    int *dp = (int*)calloc(len, sizeof(int));
    int longest = 0;

    // 第一個字元無論是 ( ) 都可忽略
    for (int i = 1; i < len; ++i) {
        if (s[i] == '(') {
            continue;
        }

        // 以下都不用判斷 s[i] 是否等於 ')'
        if (s[i - 1] == '(') {
            if (i == 1) { // 這行可移到最外層
                dp[i] = 2;
            } else {
                dp[i] = dp[i - 2] + 2;
            }
        } else { // s[i - 1] == ')'
            int prevLeftIndex = i - dp[i - 1] - 1;
            if (prevLeftIndex >= 0 && s[prevLeftIndex]== '(') {
                dp[i] = dp[i - 1] + 2;
                if ((prevLeftIndex - 1) >= 0) {
                    dp[i] += dp[prevLeftIndex - 1];
                }
            }
        }
        longest = MAX(longest, dp[i]);
    }
    free(dp);
    return longest;
}

int main() {
    char *str = (char*)"((()))())";
    printf("%s: %d\n", str, longestValidParentheses(str));
    return 0;
}


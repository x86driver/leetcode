void dfs(char *digits, char **letters, char **ans, int *ansIndex, int index) {
    static char sets[5] = {'\0', '\0', '\0', '\0', '\0'};

    if (index >= strlen(digits)) {
        strcpy(ans[*ansIndex], sets);
        ++(*ansIndex);
        return;
    }

    char *target = letters[digits[index] - '2'];
    for (int i = 0; i < strlen(target); ++i) {
        sets[strlen(sets)] = target[i];
        dfs(digits, letters, ans, ansIndex, index + 1);
        sets[strlen(sets) - 1] = '\0';
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    char *letters[] = {
        "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    *returnSize = 1;
    for (int i = 0; i < strlen(digits); ++i) {
        int index = digits[i] - '2';
        *returnSize *= strlen(letters[index]);
    }

    char **ans = (char**)calloc(*returnSize, sizeof(char**));
    for (int i = 0; i < *returnSize; ++i) {
        ans[i] = (char*)calloc(5, sizeof(char*));
    }

    int ansIndex = 0;
    dfs(digits, letters, ans, &ansIndex, 0);
    return ans;
}

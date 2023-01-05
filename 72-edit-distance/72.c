static inline int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    return c;
}

int minDistance(char * word1, char * word2){
    char new_word1[strlen(word1)+2];
    char new_word2[strlen(word2)+2];
    new_word1[0] = ' ';
    new_word1[1] = '\0';
    new_word2[0] = ' ';
    new_word2[1] = '\0';
    strcat(new_word1, word1);
    strcat(new_word2, word2);

    int f[strlen(new_word1)][strlen(new_word2)];

    for (int i = 0; i < strlen(new_word1); ++i) f[i][0] = i;
    for (int j = 0; j < strlen(new_word2); ++j) f[0][j] = j;

    for (int i = 1; i < strlen(new_word1); ++i)
        for (int j = 1; j < strlen(new_word2); ++j) {
            f[i][j] = min(f[i][j-1] + 1, f[i-1][j] + 1,
                          f[i-1][j-1] + ((new_word1[i] != new_word2[j]) ? 1 : 0));
        }

    return f[strlen(word1)][strlen(word2)];
}

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    int i = 0;
    int j = 0;
    char *a = word1[i];
    char *b = word2[j];

    while (i < word1Size && j < word2Size) {
        if (*a != *b)
            return false;
        ++a;
        ++b;
        if (*a == '\0') {
            ++i;
            if (i >= word1Size)
                break;
            a = word1[i];
        }
        if (*b == '\0') {
            ++j;
            if (j >= word2Size)
                break;
            b = word2[j];
        }
    }
    char *lastword1 = word1[word1Size - 1];
    char *lasta = lastword1 + strlen(lastword1);
    char *lastword2 = word2[word2Size - 1];
    char *lastb = lastword2 + strlen(lastword2);
    return (a == lasta && b == lastb);
}

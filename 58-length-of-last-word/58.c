int lengthOfLastWord(char * s){
    int count = 0;
    int prev = 0;
    size_t len = strlen(s);

    while (s[len] == ' ' || s[len] == NULL) {
        --len;
    }

    while (len) {
        if (s[len] == ' ' ) {
            break;
        }
        ++count;
        --len;
    }

    if (s[len] != ' ' && s[len] != NULL) {
        ++count;
    }

    return count;
}

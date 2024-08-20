int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;
    int count = 0;
    while (i >= 0) {
        if (s[i] == ' ') {
            --i;
            continue;
        } else {
            break;
        }
    }
    while (i >= 0) {
        if (s[i] == ' ')
            return count;
        ++count;
        --i;
    }
    return count;
}

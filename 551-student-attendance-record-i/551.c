bool checkRecord(char * s){
    int absent = 0;
    int late = 0;
    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] == 'A') {
            ++absent;
            late = 0;
            if (absent >= 2)
                return false;
        } else if (s[i] == 'L') {
            ++late;
            if (late >= 3)
                return false;
        } else {
            late = 0;
        }
    }

    return true;
}

char * toLowerCase(char * s){
    for (size_t i = 0; i < strlen(s); ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}

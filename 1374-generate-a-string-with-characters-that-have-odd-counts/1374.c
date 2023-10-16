char * generateTheString(int n){
    char *ret = (char*)malloc((n + 1) * sizeof(char));
    memset(ret, 'a', n * sizeof(char));
    if (n % 2 == 0)
        ret[n - 1] = 'b';
    ret[n] = '\0';
    return ret;
}

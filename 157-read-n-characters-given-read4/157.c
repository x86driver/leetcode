/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char* buf, int n) {
    char* ptr = buf;
    int ret = 0;
    for (int i = 0; i < n/4; ++i) {
        ret += read4(ptr);
        ptr += 4;
    }

    int remain = n % 4;
    char tmp[4] = {0};
    read4(tmp);

    ret += remain;
    memcpy(ptr, tmp, remain);

    return ret;
}

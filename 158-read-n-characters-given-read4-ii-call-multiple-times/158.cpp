/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    Solution() : tmp {0, 0, 0, 0},
                 index (-1),
                 read_len (0)
    {
    }
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int nread = 0;

        while (n >= 4) {
            int r = _get_from_tmp(buf, 4);
            if (r == 0)
                return nread;
            nread += r;
            buf += r;
            n -= r;
        }

        if (n) {
            nread += _get_from_tmp(buf, n);
        }

        return nread;
    }
private:
    char tmp[4];
    int read_len;
    int index;

    int _read4_to_tmp() {
        read_len = read4(tmp);
        index = (read_len ? 0 : -1);
        return read_len;
    }

    int _get(char *buf, int n) {
        int ret = 0;

        if (index == -1 && _read4_to_tmp() == 0)
            return 0;

        while (index < 4) {
            if (n == 0 || read_len == 0)
                break;
            *buf++ = tmp[index++];
            ++ret;
            --n;
            --read_len;
        }

        if (read_len == 0)
            index = -1;

        return ret;
    }

    int _get_from_tmp(char *buf, int n) {
        int ret = _get(buf, n);
        buf += ret;
        if (ret < n)
            ret += _get(buf, n - ret);

        return ret;
    }
};

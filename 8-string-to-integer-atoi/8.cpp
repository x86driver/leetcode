class Solution {
public:
    int myAtoi(string s) {
        string str;
        uint64_t num = 0;
        int i = 0;
        bool neg = false;
        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            } else {
                break;
            }
        }
        if (s[i] == '+') {
            neg = false;
            ++i;
        } else if (s[i] == '-') {
            neg = true;
            ++i;
        }
        while (i < s.size()) {
            if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9) {
                if (num >= 2147483648)
                    break;
                num = num * 10 + s[i] - '0';
                ++i;
            } else {
                break;
            }
        }
        if (!neg && num >= 2147483647) {
            return 2147483647;
        } else if (neg && num >= 2147483648) {
            return -2147483648;
        }
        if (neg)
            return -num;
        return num;
    }
};

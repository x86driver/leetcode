class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        x = abs(x);
        uint64_t ans = 0;
        while (x) {
            int digit = x % 10;
            x /= 10;
            if (ans >= 214748365)
                return 0;
            ans = ans * 10 + digit;
        }
        if (neg)
            return -ans;
        else
            return ans;
    }
};

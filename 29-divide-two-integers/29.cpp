class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        bool dividend_pos = dividend >= 0;
        bool divisor_pos = divisor >= 0;

        if (divisor == 1)
            return dividend;
        else if (divisor == -1) {
            if (dividend <= -2147483648)
                return 2147483647;
            return -dividend;
        }

        int64_t dividend64 = abs((int64_t)dividend);
        int64_t divisor64 = abs((int64_t)divisor);

        while (dividend64 - divisor64 >= 0) {
            dividend64 -= divisor64;
            ++quotient;
        }

        if ((dividend_pos && divisor_pos) || (!dividend_pos && !divisor_pos)) {
            return quotient;
        } else {
            return -quotient;
        }
    }
};

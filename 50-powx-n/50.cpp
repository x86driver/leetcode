class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        bool isNegative = n < 0;
        //return pow(x, n);
        if (x == 1) {
            return 1;
        }
        if (x == -1) {
            if ((n % 2) == 0) {
                return 1;
            } else {
                return -1;
            }
        }
        if (n <= -20) {
            return 0;
        }
        uint64_t count = labs(n);
        for (uint64_t i = 0; i < count; i++) {
            result *= x;
        }
        if (isNegative) {
            return 1.0 / result;
        } else {
            return result;
        }
    }
};

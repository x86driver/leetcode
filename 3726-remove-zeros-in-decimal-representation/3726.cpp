class Solution {
public:
    long long removeZeros(long long n) {
        long long result = 0;
        vector<int> digits;
        while (n) {
            int digit = n % 10;
            if (digit != 0) {
                digits.push_back(digit);
            }
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int d : digits) {
            result *= 10;
            result += d;
        }
        return result;
    }
};

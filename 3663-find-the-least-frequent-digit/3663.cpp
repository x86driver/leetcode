class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> digits(10);
        while (n > 0) {
            int digit = n % 10;
            ++digits[digit];
            n /= 10;
        }
        int ans = 0;
        int least = INT_MAX;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > 0 && digits[i] <= least) {
                least = digits[i];
                ans = i;
            }
        }
        return ans;
    }
};

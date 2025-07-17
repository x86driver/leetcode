class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end());
        int end = digits.size() - 1;
        return digits[end] * digits[end - 1];
    }
};

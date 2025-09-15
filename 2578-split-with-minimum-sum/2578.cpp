class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        int num1 = 0;
        int num2 = 0;
        int i = 0;
        while (i < digits.size()) {
            num1 *= 10;
            num1 += digits[i];
            ++i;
            if (i < digits.size()) {
                num2 *= 10;
                num2 += digits[i];
                ++i;
            }
        }
        return num1 + num2;
    }
};

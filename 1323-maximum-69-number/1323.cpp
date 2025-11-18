class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int ans = 0;
        bool changed = false;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ans *= 10;
            if (digits[i] == 6 && !changed) {
                ans += 9;
                changed = true;
            } else {
                ans += digits[i];
            }
        }
        return ans;
    }
};

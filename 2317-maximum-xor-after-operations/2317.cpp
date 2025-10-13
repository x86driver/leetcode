class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> digits(32);
        for (int n : nums) {
            for (int i = 0; i < digits.size(); ++i) {
                int bit = n & 0x01;
                digits[i] += bit;
                n >>= 1;
            }
        }
        int ans = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            ans <<= 1;
            if (digits[i] == 0) {
                continue;
            } else {
                ans |= 0x01;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int m[51] = {0};
        for (int n : nums) {
            ++m[n];
        }
        int ans = 0;
        for (int i = 1; i <= 50; ++i) {
            if (m[i] > 1) {
                ans ^= i;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xored = 0;
        for (int n : nums) {
            xored ^= n;
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if ((xored & 0x01) != (k & 0x01)) {
                ++ans;
            }
            xored >>= 1;
            k >>= 1;
        }
        return ans;
    }
};

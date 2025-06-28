class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int x = nums[i];
                int y = nums[j];
                if (abs(x - y) <= min(x, y)) {
                    ans = max(ans, x ^ y);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                dp[j] = max(dp[j], dp[i] + (j - i) * nums[j]);
            }
        }
        int ans = 0;
        for (int n : dp) {
            ans = max(ans, n);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmax = nums[0];
        int fmin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int tmp_fmax = max({nums[i], fmax * nums[i], fmin * nums[i]});
            int tmp_fmin = min({nums[i], fmax * nums[i], fmin * nums[i]});
            fmax = tmp_fmax;
            fmin = tmp_fmin;
            ans = max(ans, fmax);
        }

        return ans;
    }
};

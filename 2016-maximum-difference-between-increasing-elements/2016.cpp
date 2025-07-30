class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> prefix_min(nums.size());
        prefix_min[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < prefix_min[i - 1]) {
                prefix_min[i] = nums[i];
            } else {
                prefix_min[i] = prefix_min[i - 1];
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < nums.size(); ++i) {
            if (prefix_min[i] < nums[i]) {
                ans = max(ans, nums[i] - prefix_min[i]);
            }
        }
        if (ans == INT_MIN) {
            return -1;
        }
        return ans;
    }
};

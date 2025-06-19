class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(nums[0]);
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            ans.push_back(nums[i]);
            int sum = accumulate(ans.begin(), ans.end(), 0);
            int rest = accumulate(nums.begin() + i + 1, nums.end(), 0);
            if (sum > rest)
                break;
        }
        return ans;

    }
};

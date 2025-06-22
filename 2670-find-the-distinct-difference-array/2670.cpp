class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> prefix, suffix;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            ++suffix[nums[i]];
        }
        for (int i = 0; i < nums.size(); ++i) {
            ++prefix[nums[i]];
            --suffix[nums[i]];
            if (suffix[nums[i]] == 0) {
                suffix.erase(nums[i]);
            }
            ans.push_back(prefix.size() - suffix.size());
        }
        return ans;
    }
};

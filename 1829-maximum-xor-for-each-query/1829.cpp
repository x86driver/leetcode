class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> prefix;
        prefix.reserve(nums.size());
        prefix.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            prefix.push_back(prefix[i - 1] ^ nums[i]);
        }

        vector<int> ans;
        ans.reserve(nums.size());
        int maxVal = (2 << (maximumBit - 1)) - 1;
        for (int pre : prefix) {
            ans.push_back(pre ^ maxVal);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size() - 1);
        for (int i = 0; i < nums.size() - 1; i++) {
            ans.push_back(nums[i] | nums[i + 1]);
        }
        return ans;
    }
};

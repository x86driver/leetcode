class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < nums.size() || j < nums.size()) {
            while (i < nums.size()) {
                if (nums[i] > 0) {
                    ans.push_back(nums[i]);
                    ++i;
                    break;
                }
                ++i;
            }
            while (j < nums.size()) {
                if (nums[j] < 0) {
                    ans.push_back(nums[j]);
                    ++j;
                    break;
                }
                ++j;
            }
        }
        return ans;
    }
};

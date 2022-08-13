class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> prefix_l(nums.size()+1);
        vector<int> prefix_r(nums.size()+1);

        prefix_l[0] = 1;
        prefix_r[nums.size()] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            prefix_l[i+1] = prefix_l[i] * nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; --i) {
            prefix_r[i] = prefix_r[i+1] * nums[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            ans.push_back(prefix_l[i] * prefix_r[i+1]);
        }

        return ans;
    }
};

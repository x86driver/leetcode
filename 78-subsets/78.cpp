class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void bt(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        bt(nums, index + 1);
        tmp.pop_back();

        bt(nums, index + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        bt(nums, 0);
        return ans;
    }
};

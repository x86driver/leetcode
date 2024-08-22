class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> mask;
    void bt(vector<int>& nums, int index) {
        if (index >= nums.size() || tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!mask[i]) {
                mask[i] = true;
                tmp.push_back(nums[i]);
                bt(nums, index + 1);
                tmp.pop_back();
                mask[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        mask.resize(nums.size());
        bt(nums, 0);
        return ans;
    }
};

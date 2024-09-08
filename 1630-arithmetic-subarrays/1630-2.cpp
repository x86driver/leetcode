class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); ++i) {
            vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(tmp.begin(), tmp.end());
            int comp = tmp[1] - tmp[0];
            bool ret = true;
            for (int j = 2; j < tmp.size(); ++j) {
                if (tmp[j] - tmp[j - 1] != comp) {
                    ret = false;
                    break;
                }
            }
            ans[i] = ret;
        }
        return ans;
    }
};

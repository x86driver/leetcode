class Solution {
private:
    vector<int> reform(vector<int>& nums, int start, int end) {
        vector<int> ret;
        for (int i = start; i < end + 1; ++i)
            ret.push_back(nums[i]);
        sort(ret.begin(), ret.end());
        return ret;
    }
    bool check(vector<int>& nums) {
        int diff = nums[1] - nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] != diff)
                return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); ++i) {
            vector<int> sub = reform(nums, l[i], r[i]);
            ans.push_back(check(sub));
        }
        return ans;
    }
};

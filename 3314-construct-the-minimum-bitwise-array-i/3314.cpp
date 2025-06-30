class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int n : nums) {
            bool found = false;
            for (int i = 1; i <= 1000; ++i) {
                int tmp = i | (i + 1);
                if (tmp == n) {
                    ans.push_back(i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

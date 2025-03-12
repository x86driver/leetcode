class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> m(101);
        for (int n : nums) {
            ++m[n];
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for (int n : nums) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                count += m[i];
            }
            ans.push_back(count);
        }
        return ans;
    }
};

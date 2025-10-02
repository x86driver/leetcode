class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<>());
        set<int> s;
        vector<int> ans;
        int i = 0;
        while (i < nums.size() && ans.size() < k) {
            if (s.find(nums[i]) == s.end()) {
                ans.push_back(nums[i]);
                s.insert(nums[i]);
            }
            ++i;
        }
        return ans;
    }
};

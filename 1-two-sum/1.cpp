class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
            m.insert({nums[i], i});

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int n = target - nums[i];
            if (m.find(n) != m.end() && m[n] != i) {
                ans.push_back(i);
                ans.push_back(m[n]);
                break;
            }
        }

        return ans;
    }
};

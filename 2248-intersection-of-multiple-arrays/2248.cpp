class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> m(1001);
        for (const vector<int>& num : nums) {
            for (int n : num)
                ++m[n];
        }
        vector<int> ans;
        const int size = nums.size();
        for (int i = 1; i < m.size(); ++i) {
            if (m[i] == size)
                ans.push_back(i);
        }
        return ans;
    }
};

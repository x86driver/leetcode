class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> m(101);
        for (const vector<int>& array : arrays) {
            for (int n : array) {
                ++m[n];
            }
        }
        vector<int> ans;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] >= arrays.size()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

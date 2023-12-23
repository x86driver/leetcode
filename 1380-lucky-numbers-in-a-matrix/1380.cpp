class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> row;
        vector<int> ans;
        for (int i = 0; i < matrix.size(); ++i) {
            row.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            int maximum = INT_MIN;
            for (int j = 0; j < matrix.size(); ++j) {
                maximum = max(maximum, matrix[j][i]);
            }
            if (row.find(maximum) != row.end())
                ans.push_back(maximum);
        }

        return ans;
    }
};

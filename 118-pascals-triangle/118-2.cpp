class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1) {
            return ans;
        }
        ans.push_back({1, 1});
        for (int i = 2; i < numRows; i++) {
            vector<int> row = {1};
            for (int j = 1; j < i; j++) {
                int val1 = ans[i - 1][j - 1];
                int val2 = ans[i - 1][j];
                row.push_back(val1 + val2);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};

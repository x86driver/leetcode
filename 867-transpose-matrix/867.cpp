class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>> row;
        vector<pair<int,int>> col;
        for (int i = 0; i < grid.size(); ++i) {
            int zero = 0;
            int one = 0;
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++zero;
                } else {
                    ++one;
                }
            }
            row.push_back({zero, one});
        }
        for (int i = 0; i < grid[0].size(); ++i) {
            int zero = 0;
            int one = 0;
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[j][i] == 0) {
                    ++zero;
                } else {
                    ++one;
                }
            }
            col.push_back({zero, one});
        }
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = row[i].second + col[j].second - row[i].first - col[j].first;
            }
        }
        return ans;
    }
};

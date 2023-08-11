class Solution {
private:
    int m, n;
    int onesRow(vector<vector<int>>& grid, int row) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += grid[row][i];
        }
        return count;
    }
    int onesCol(vector<vector<int>>& grid, int col) {
        int count = 0;
        for (int i = 0; i < m; ++i) {
            count += grid[i][col];
        }
        return count;
    }
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> cols(n);
        for (int j = 0; j < n; ++j)
            cols[j] = onesCol(grid, j);
        for (int i = 0; i < m; ++i) {
            int onesrow0 = onesRow(grid, i);
            int zerosrow0 = m - onesrow0;
            for (int j = 0; j < n; ++j) {
                int onescol0 = cols[j];
                int zeroscol0 = n - onescol0;
                ans[i][j] = onesrow0 + onescol0 - zerosrow0 - zeroscol0;
            }
        }
        return ans;
    }
};

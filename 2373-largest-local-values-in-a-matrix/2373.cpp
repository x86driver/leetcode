class Solution {
private:
    int maxMatrix(vector<vector<int>>& grid, int x, int y) {
        int maximum = 0;
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                maximum = max(maximum, grid[i][j]);
            }
        }
        return maximum;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        for (int i = 0; i < grid.size() - 2; ++i) {
            vector<int> row;
            for (int j = 0; j < grid[i].size() - 2; ++j) {
                row.push_back(maxMatrix(grid, i, j));
            }
            ans.push_back(row);
        }
        return ans;
    }
};

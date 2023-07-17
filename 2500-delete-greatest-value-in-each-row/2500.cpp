class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
            sort(grid[i].begin(), grid[i].end(), greater<int>());

        int val = 0;
        int maximum = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            maximum = grid[0][i];
            for (int col = 0; col < grid.size(); ++ col) {
                maximum = max(maximum, grid[col][i]);
            }
            val += maximum;
        }
        return val;
    }
};

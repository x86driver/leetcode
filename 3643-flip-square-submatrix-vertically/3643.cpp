class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top_x = x;
        int bottom_x = x + k - 1;
        while (top_x < bottom_x) {
            for (int i = y; i < y + k; ++i) {
                swap(grid[top_x][i], grid[bottom_x][i]);
            }
            ++top_x;
            --bottom_x;
        }
        return grid;
    }
};

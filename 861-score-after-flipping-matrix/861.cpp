class Solution {
private:
    void flip_row(vector<vector<int>>& grid, int row) {
        for (int i = 0; i < grid[0].size(); ++i) {
            grid[row][i] ^= 1;
        }
    }
    void flip_col(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); ++i) {
            grid[i][col] ^= 1;
        }
    }
    bool need_flip_col(vector<vector<int>>& grid, int col) {
        int ones = 0;
        for (int i = 0; i < grid.size(); ++i) {
            ones += grid[i][col];
        }
        return (ones <= grid.size() / 2);
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            if (grid[row][0] == 0) {
                flip_row(grid, row);
            }
        }
        for (int col = 0; col < grid[0].size(); ++col) {
            if (need_flip_col(grid, col)) {
                flip_col(grid, col);
            }
        }

        int sum = 0;
        for (const vector<int> row : grid) {
            int temp = 0;
            for (int n : row) {
                temp <<= 1;
                temp |= n;
            }
            sum += temp;
        }
        return sum;
    }
};

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (const vector<int>& index : indices) {
            int row = index[0];
            int col = index[1];
            for (int i = 0; i < n; ++i)
                ++matrix[row][i];
            for (int i = 0; i < m; ++i)
                ++matrix[i][col];
        }

        int count = 0;
        for (vector<int>& row : matrix) {
            for (int x : row)
                if (x % 2 == 1)
                    ++count;
        }

        return count;
    }
};

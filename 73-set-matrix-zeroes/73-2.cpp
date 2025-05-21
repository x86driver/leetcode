class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int row : rows) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[row][j] = 0;
            }
        }
        for (int col : cols) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int row = 0; row < matrix[0].size(); ++row) {
            int maximum = -1;
            vector<int> cols;
            for (int col = 0; col < matrix.size(); ++col) {
                maximum = max(maximum, matrix[col][row]);
                if (matrix[col][row] == -1) {
                    cols.push_back(col);
                }
            }
            for (int c : cols) {
                matrix[c][row] = maximum;
            }
        }

        return matrix;
    }
};

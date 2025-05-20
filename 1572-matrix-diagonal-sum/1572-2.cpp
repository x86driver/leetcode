class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for (int row = 0; row < mat.size(); ++row) {
            sum += mat[row][row];
        }
        int row = 0;
        for (int col = mat[0].size() - 1; col >= 0; --col) {
            sum += mat[row++][col];
        }
        if ((mat.size() % 2) == 1) {
            int mid = mat.size() / 2;
            sum -= mat[mid][mid];
        }
        return sum;
    }
};

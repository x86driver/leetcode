class Solution {
private:
    bool isSpecial(vector<vector<int>>& mat, int x, int y) {
        for (int col = 0; col < mat[x].size(); ++col) {
            if (mat[x][col] == 0) {
                continue;
            } else if (col == y) {
                continue;
            } else {
                return false;
            }
        }

        for (int row = 0; row < mat.size(); ++row) {
            if (mat[row][y] == 0) {
                continue;
            } else if (row == x) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for (int row = 0; row < mat.size(); ++row) {
            for (int col = 0; col < mat[row].size(); ++col) {
                if (mat[row][col] == 1 && isSpecial(mat, row, col)) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

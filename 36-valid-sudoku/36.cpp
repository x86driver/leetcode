class Solution {
private:
    bool isValidBox(const vector<vector<char>>& board, int x, int y) {
        vector<bool> nums(10);
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j] - '0';
                if (nums[val]) {
                    return false;
                } else {
                    nums[val] = true;
                }
            }
        }
        return true;
    }
    bool isValidRow(const vector<vector<char>>& board, int row) {
        vector<bool> nums(10);
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == '.') {
                continue;
            }
            int val = board[row][i] - '0';
            if (nums[val]) {
                return false;
            } else {
                nums[val] = true;
            }
        }
        return true;
    }
    bool isValidCol(const vector<vector<char>>& board, int col) {
        vector<bool> nums(10);
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == '.') {
                continue;
            }
            int val = board[i][col] - '0';
            if (nums[val]) {
                return false;
            } else {
                nums[val] = true;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // i = 0, 3, 6
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isValidBox(board, i, j)) {
                    return false;
                }
                cout << endl;
            }
        }

        for (int row = 0; row < 9; ++row) {
            if (!isValidRow(board, row)) {
                return false;
            }
        }

        for (int col = 0; col < 9; ++col) {
            if (!isValidCol(board, col)) {
                return false;
            }
        }

        return true;
    }
};

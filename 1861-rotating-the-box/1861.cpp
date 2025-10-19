class Solution {
private:
    void shiftRight(vector<char>& row) {
        int stones = 0;
        int empties = 0;
        row.push_back('*');
        for (int i = 0; i < row.size(); ++i) {
            if (row[i] == '#') {
                ++stones;
            } else if (row[i] == '.') {
                ++empties;
            } else if (row[i] == '*') { // obstacle
                int index = i - 1;
                while (index >= 0 && stones) {
                    row[index] = '#';
                    --index;
                    --stones;
                }
                while (index >= 0 && empties) {
                    row[index] = '.';
                    --index;
                    --empties;
                }
                stones = 0;
                empties = 0;
            }
        }
        row.pop_back();
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        for (vector<char>& row : boxGrid) {
            shiftRight(row);
        }

        int new_width = boxGrid.size();
        int new_height = boxGrid[0].size();
        vector<vector<char>> ans(new_height, vector<char>(new_width));

        int x = 0;
        int y = 0;
        for (int i = 0; i < boxGrid[0].size(); ++i) {
            for (int j = boxGrid.size() - 1; j >= 0; --j) {
                ans[x][y] = boxGrid[j][i];
                ++y;
                if (y >= new_width) {
                    y = 0;
                    ++x;
                }
            }
        }
        return ans;
    }
};

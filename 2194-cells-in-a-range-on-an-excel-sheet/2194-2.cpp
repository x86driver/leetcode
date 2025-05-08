class Solution {
public:
    vector<string> cellsInRange(string s) {
        int colStart = s[0] - 'A';
        int colEnd = s[3] - 'A';
        int rowStart = s[1] - '0';
        int rowEnd = s[4] - '0';

        vector<string> ans;
        for (int i = colStart; i <= colEnd; ++i) {
            char col = i + 'A';
            for (int j = rowStart; j <= rowEnd; ++j) {
                char row = j + '0';
                char cell[3] = {0};
                cell[0] = col;
                cell[1] = row;
                ans.push_back(cell);
            }
        }

        return ans;
    }
};

class Solution {
private:
    void clearRow(vector<vector<int>>& matrix, int row) {
        //cout << "Clear row " << row << endl;
        for (int i = 0; i < matrix[row].size(); ++i) {
            //cout << row << "," << i << endl;
            matrix[row][i] = 0;
        }
    }
    void clearCol(vector<vector<int>>& matrix, int col) {
        //cout << "Clear col " << col << endl;
        for (int i = 0; i < matrix.size(); ++i) {
            //cout << i << "," << col << endl;
            matrix[i][col] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> locations;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    locations.push_back({i, j});
                }
            }
        }

        for (const vector<int>& loc : locations) {
            clearRow(matrix, loc[0]);
            clearCol(matrix, loc[1]);
        }
    }
};

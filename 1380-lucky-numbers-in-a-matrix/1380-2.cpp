class Solution {
private:
    int get_col_max(vector<vector<int>>& matrix, int col) {
        int maximum = INT_MIN;
        for (int i = 0; i < matrix.size(); ++i) {
            maximum = max(maximum, matrix[i][col]);
        }
        return maximum;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); ++i) {
            int minimum = INT_MAX;
            int min_index = -1;
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] <= minimum) {
                    minimum = matrix[i][j];
                    min_index = j;
                }
            }
            int maximum = get_col_max(matrix, min_index);
            if (minimum == maximum) {
                ans.push_back(minimum);
            }
        }
        return ans;
    }
};


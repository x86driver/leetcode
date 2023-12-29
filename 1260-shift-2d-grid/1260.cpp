class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> array;
        for (const vector<int>& row : grid) {
            for (int n : row) {
                array.push_back(n);
            }
        }

        k = k % array.size();
        rotate(array.begin(), array.end() - k, array.end());

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int index = i * grid[i].size() + j;
                grid[i][j] = array[index];
            }
        }

        return grid;
    }
};

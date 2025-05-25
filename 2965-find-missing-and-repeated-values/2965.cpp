class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        map<int, bool> m;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (m[grid[i][j]]) {
                    ans.push_back(grid[i][j]);
                }
                m[grid[i][j]] = true;
            }
        }
        for (int i = 1; i < grid.size() * grid[0].size() + 1; ++i) {
            if (!m[i]) {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};

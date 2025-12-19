class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int i = 0; i < grid[0].size(); ++i) {
            int length = 0;
            for (int j = 0; j < grid.size(); ++j) {
                int num = grid[j][i];
                int len = 0;
                if (num == 0 || num < 0) {
                    ++len;
                }
                while (num != 0) {
                    num /= 10;
                    ++len;
                }
                length = max(length, len);
            }
            ans.push_back(length);
        }

        return ans;
    }
};

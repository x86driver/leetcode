class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;
        const int dx[] = {1, 0, 0, -1};
        const int dy[] = {0, 1, -1, 0};

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0)
                    continue;
                total += 4;
                for (int k = 0; k < 4; ++k) {
                    int newx = i + dx[k];
                    int newy = j + dy[k];
                    if (newx < 0 || newy < 0 || newx >= grid.size() || newy >= grid[0].size())
                        continue;
                    if (grid[newx][newy] == 1)
                        --total;
                }
            }
        }

        return total;
    }
};

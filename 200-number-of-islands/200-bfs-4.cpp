class Solution {
private:
    int m, n;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void bfs(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [sx, sy] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = sx + dx[i];
                int newY = sy + dy[i];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == '1') {
                    grid[newX][newY] = '0';
                    q.push({newX, newY});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};

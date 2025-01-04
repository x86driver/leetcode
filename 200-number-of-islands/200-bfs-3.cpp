class Solution {
private:
    int m, n;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    bool bfs(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '0') {
            return false;
        }
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [X, Y] = q.front();
            q.pop();
            grid[X][Y] = '0';
            for (int i = 0; i < 4; i++) {
                int newX = X + dx[i];
                int newY = Y + dy[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == '0') {
                    continue;
                }
                grid[newX][newY] = '0';
                q.push({newX, newY});
            }
        }
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && bfs(grid, i, j)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

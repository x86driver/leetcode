class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        this->m = grid.size();
        this->n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    bfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
private:
    int m;
    int n;
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    vector<vector<bool>> visit;
    void bfs(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = true;
        while (!q.empty()) {
            int sx = q.front().first;
            int sy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = sx + dx[i];
                int ny = sy + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (!visit[nx][ny] && grid[nx][ny] == '1') {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }
    }
};

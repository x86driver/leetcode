class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1' && !visit[i][j]) {
                    ++ans;
                    bfs(grid, i, j);
                }

        return ans;
    }

private:
    void bfs(vector<vector<char>>& grid, int sx, int sy) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        visit[sx][sy] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (grid[nx][ny] == '1' && !visit[nx][ny]) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }
    }

    int m;
    int n;
    vector<vector<bool>> visit;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
};

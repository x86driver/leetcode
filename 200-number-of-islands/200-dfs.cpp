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
                    dfs(grid, i, j);
                }

        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        visit[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (grid[nx][ny] == '1' && !visit[nx][ny])
                dfs(grid, nx, ny);
        }
    }

    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    vector<vector<bool>> visit;
    int m;
    int n;
};

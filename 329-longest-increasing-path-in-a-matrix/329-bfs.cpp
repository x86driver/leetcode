class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->path = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (path[i][j] == 0)
                    bfs(matrix, i, j);
            }
        }

        int maxPath = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maxPath = max(maxPath, path[i][j]);

        return maxPath;
    }

private:
    void bfs(vector<vector<int>>& matrix, int sx, int sy) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        path[sx][sy] = max(path[sx][sy], 1);

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (matrix[nx][ny] > matrix[x][y]) {
                    if (path[nx][ny] == 0 || path[nx][ny] <= path[x][y])
                        q.push({nx, ny});
                    path[nx][ny] = max(path[nx][ny], path[x][y] + 1);
                }
            }
        }
    }

    int m;
    int n;
    vector<vector<int>> path;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
};

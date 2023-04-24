class Solution {
private:
    int m;
    int n;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> path;

    void bfs(vector<vector<int>>& matrix, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        path[x][y] = max(path[x][y], 1);
        while (!q.empty()) {
            int sx = q.front().first;
            int sy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = sx + dx[i];
                int ny = sy + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (matrix[nx][ny] > matrix[sx][sy] && path[nx][ny] <= path[sx][sy]) {
                    q.push({nx, ny});
                    path[nx][ny] = max(path[nx][ny], path[sx][sy] + 1);
                }
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        path = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bfs(matrix, i, j);
                cout << endl;
            }
        }

        int maximum = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maximum = max(maximum, path[i][j]);

        return maximum;
    }
};

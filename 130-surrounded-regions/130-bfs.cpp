class Solution {
public:
    void solve(vector<vector<char>>& board) {
        this->m = board.size();
        this->n = board[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visit[0][j])
                bfs(board, 0, j);
            if (board[m - 1][j] == 'O' && !visit[m - 1][j])
                bfs(board, m - 1, j);
        }

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visit[i][0])
                bfs(board, i, 0);
            if (board[i][n - 1] == 'O' && !visit[i][n - 1])
                bfs(board, i, n - 1);
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'O' && !visit[i][j])
                    board[i][j] = 'X';
    }

private:
    void bfs(vector<vector<char>>& board, int sx, int sy) {
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
                if (board[nx][ny] == 'O' && !visit[nx][ny]) {
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

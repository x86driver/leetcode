class Solution {
private:
    int m, n;
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            int sx = q.front().first;
            int sy = q.front().second;
            q.pop();
            visit[sx][sy] = true;
            for (int i = 0; i < 4; i++) {
                int newX = sx + dx[i];
                int newY = sy + dy[i];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && board[newX][newY] == 'O' && visit[newX][newY] == false) {
                    visit[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (board[i][j] == 'O' && !visit[i][j]) {
                        bfs(board, visit, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visit[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};

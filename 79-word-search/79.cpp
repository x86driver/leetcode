class Solution {
private:
    int m;
    int n;
    vector<vector<bool>> visit;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    bool dfs(vector<vector<char>>& board, string word, int x, int y) {
        visit[x][y] = true;
        if (word.empty())
            return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            //cout << "board[" << nx << "][" << ny << "]: " << board[nx][ny] << " visit: " << visit[nx][ny] << endl;
            if (!visit[nx][ny] && word[0] == board[nx][ny]) {
                //cout << "board[" << nx << "][" << ny << "]: " << board[nx][ny] << " visit: " << visit[nx][ny] << endl;
                if (dfs(board, word.substr(1), nx, ny))
                    return true;
            }
        }
        visit[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visit = vector<vector<bool>>(m, vector<bool>(n));
                if (!visit[i][j] && board[i][j] == word[0]) {
                    if (dfs(board, word.substr(1), i, j))
                        return true;
                }
            }
        }

        return false;
    }
};

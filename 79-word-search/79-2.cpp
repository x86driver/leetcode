class Solution {
private:
    bool dfs(const vector<vector<char>>& board, int x, int y, const string& word, int index, vector<vector<bool>>& visit) {
        if (board[x][y] != word[index]) {
            visit[x][y] = false;
            return false;
        }
        if (visit[x][y]) {
            return false;
        }
        //cout << word[index] << " ";
        visit[x][y] = true;
        if (word.size() == index + 1) {
            //cout << " found" << endl;
            return true;
        }
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        bool result = false;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= board.size() || newY < 0 || newY >= board[x].size() || visit[newX][newY]) {
                continue;
            }
            bool tmp = dfs(board, newX, newY, word, index + 1, visit);
            if (tmp) {
                result = true;
            } else {
                visit[newX][newY] = false;
            }
        }
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, word, 0, visit)) {
                    return true;
                }
                //cout << endl;
                for (auto& row : visit) {
                    fill(row.begin(), row.end(), false);
                }
            }
        }
        return false;
    }
};

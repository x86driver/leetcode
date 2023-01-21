class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        int m = image.size();
        int n = image[0].size();
        int orig_color = image[sr][sc];
        queue<pair<int, int>> q;

        if (image[sr][sc] != color)
            q.push({sr, sc});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = color;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (image[nx][ny] == orig_color)
                    q.push({nx, ny});
            }
        }

        return image;
    }
};

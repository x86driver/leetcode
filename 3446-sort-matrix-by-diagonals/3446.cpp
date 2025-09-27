class Solution {
private:
    vector<int> copyDiagonal(vector<vector<int>>& grid, int startX, int startY) {
        vector<int> diagonal;
        diagonal.reserve(grid.size());
        const int border = grid.size();
        while (startX < border && startY < border) {
            diagonal.push_back(grid[startX][startY]);
            ++startX;
            ++startY;
        }
        return diagonal;
    }
    void pasteDiagonal(vector<vector<int>>& grid, vector<int>& diagonal, int startX, int startY) {
        const int border = grid.size();
        int i = 0;
        while (startX < border && startY < border && i < diagonal.size()) {
            grid[startX][startY] = diagonal[i];
            ++startX;
            ++startY;
            ++i;
        }
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for (int startX = grid.size() - 1; startX >= 0; --startX) {
            vector<int> diagonal = copyDiagonal(grid, startX, 0);
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            pasteDiagonal(grid, diagonal, startX, 0);
        }
        for (int startY = 1; startY < grid.size(); ++startY) {
            vector<int> diagonal = copyDiagonal(grid, 0, startY);
            sort(diagonal.begin(), diagonal.end());
            pasteDiagonal(grid, diagonal, 0, startY);
        }
        return grid;
    }
};

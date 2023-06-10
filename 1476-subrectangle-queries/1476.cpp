class SubrectangleQueries {
private:
    int **rec;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = new int*[rectangle.size()];
        for (int i = 0; i < rectangle.size(); ++i) {
            rec[i] = new int[rectangle[i].size()];
            copy(rectangle[i].begin(), rectangle[i].end(), rec[i]);
        }
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            fill(rec[i] + col1, rec[i] + col2 + 1, newValue);
        }
    }

    int getValue(int row, int col) {
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

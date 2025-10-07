class Solution {
private:
    bool allOnes(const vector<vector<int>>& matrix, int startX, int startY, int length) {
        int endX = startX + length;
        int endY = startY + length;
        //cout << "Range: (" << startY << "," << startX << ") - (" << endY << "," << endX << ")" << endl;
        if (endX >= matrix[0].size() || endY >= matrix.size()) {
            return false;
        }
        for (int y = startY; y <= endY; ++y) {
            for (int x = startX; x <= endX; ++x) {
                //cout << "check: " << y << "," << x << endl;
                if (matrix[y][x] != 1) {
                    //cout << y << "," << x << " not one" << endl;
                    return false;
                }
            }
        }
        //cout << "Check done" << endl;
        return true;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int square = min(matrix.size(), matrix[0].size());
        for (int y = 0; y < matrix.size(); ++y) {
            for (int x = 0; x < matrix[0].size(); ++x) {
                for (int length = 0; length < square; ++length) {
                    //cout << "Start check: " << y << "," << x << ", length: " << length << endl;
                    if (allOnes(matrix, x, y, length)) {
                        //cout << "AllOnes: " << y << "," << x << ", length: " << length << endl;
                        ++count;
                    } else {
                        break;
                    }
                }
            }
        }
        return count;
    }
};

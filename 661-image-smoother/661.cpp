class Solution {
private:
    pair<int, int> getPoint(vector<vector<int>>& img, int x, int y) {
        int val = 0;
        int count = 0;
        if (x >= 0 && x < img.size() && y >= 0 && y < img[x].size()) {
            val = img[x][y];
            count = 1;
        }
        return make_pair(val, count);
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans;

        for (int x = 0; x < img.size(); ++x) {
            vector<int> row;
            for (int y = 0; y < img[x].size(); ++y) {
                pair<int, int> points[9];
                points[0] = getPoint(img, x-1, y-1);
                points[1] = getPoint(img, x-1, y);
                points[2] = getPoint(img, x-1, y+1);
                points[3] = getPoint(img, x, y-1);
                points[4] = getPoint(img, x, y);
                points[5] = getPoint(img, x, y+1);
                points[6] = getPoint(img, x+1, y-1);
                points[7] = getPoint(img, x+1, y);
                points[8] = getPoint(img, x+1, y+1);

                int val = 0;
                int count = 0;
                for (int i = 0; i < 9; ++i) {
                    val += points[i].first;
                    count += points[i].second;
                }
                row.push_back(floor(val/count));
            }
            ans.push_back(row);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans(image.size());
        for (int i = 0; i < image.size(); ++i) {
            const vector<int>& row = image[i];
            vector<int> flip(row.size());
            for (int j = row.size() - 1; j >= 0; --j) {
                if (row[j] == 0)
                    flip[row.size() - j - 1] = 1;
                else
                    flip[row.size() - j - 1] = 0;
            }
            ans[i] = move(flip);
        }
        return ans;
    }
};

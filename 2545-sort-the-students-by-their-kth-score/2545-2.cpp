class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int, int>> cols;
        cols.reserve(score.size());
        for (int i = 0; i < score.size(); ++i) {
            cols.push_back({score[i][k], i});
        }
        sort(cols.begin(), cols.end());
        vector<vector<int>> ans;
        for (int i = cols.size() - 1; i >= 0; --i) {
            ans.push_back(move(score[cols[i].second]));
            /*
            vector<int> tmp;
            for (int j = 0; j < score[0].size(); ++j) {
                tmp.push_back(score[cols[i].second][j]);
            }
            ans.push_back(tmp);
            */
        }
        return ans;
    }
};

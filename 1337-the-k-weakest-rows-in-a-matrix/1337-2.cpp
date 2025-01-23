class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;
        for (int i = 0; i < mat.size(); ++i) {
            bool finish = false;
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 0) {
                    rows.push_back({i, j});
                    finish = true;
                    break;
                }
            }
            if (!finish) {
                rows.push_back({i, mat[i].size()});
            }
        }
        sort(rows.begin(), rows.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = rows[i].first;
        }
        return ans;
    }
};

class Solution {
private:
    int soldiers(const vector<int>& row) {
        int left = 0;
        int right = row.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 1)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < mat.size(); ++i) {
            vec.push_back({i, soldiers(mat[i])});
        }

        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int> &b) {
            if (a.second == b.second)
                return a.first < b.first;
            else
                return a.second < b.second;
        });

        vector<int> ans(k);
        for (int i = 0; i < k; ++i)
            ans[i] = vec[i].first;
        return ans;
    }
};

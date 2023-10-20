class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> m(1001);
        for (const vector<int>& item : items1) {
            m[item[0]] += item[1];
        }
        for (const vector<int>& item : items2) {
            m[item[0]] += item[1];
        }
        vector<vector<int>> ans;
        for (int i = 1; i < m.size(); ++i) {
            if (m[i] != 0)
                ans.push_back({i, m[i]});
        }
        return ans;
    }
};

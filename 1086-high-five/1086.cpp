class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> m(1001, vector<int>());
        for (const vector<int>& item : items) {
            vector<int> &five = m[item[0]];
            five.push_back(item[1]);
        }
        vector<vector<int>> ans;
        for (int i = 1; i < m.size(); ++i) {
            vector<int> &five = m[i];
            if (five.size() > 0) {
                sort(five.begin(), five.end(), greater<int>());
                int average = accumulate(five.begin(), five.begin() + 5, 0) / 5;
                ans.push_back({i, average});
            }
        }
        return ans;
    }
};

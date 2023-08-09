class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        map<int, set<int>> m;
        for (const vector<int>& log : logs) {
            int id = log[0];
            int t = log[1];
            m[id].insert(t);
        }
        map<int, int> uam; // time -> numbers
        for (const pair<int, set<int>>& p : m) {
            ++uam[p.second.size()];
        }
        for (int i = 0; i < k; ++i) {
            ans[i] = uam[i + 1];
        }
        return ans;
    }
};

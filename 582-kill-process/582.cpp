class Solution {
private:
    vector<int> ans;
    void dfs(unordered_map<int, vector<int>>& m, int kill) {
        ans.push_back(kill);
        if (m.find(kill) != m.end()) {
            for (int i = 0; i < m[kill].size(); i++) {
                dfs(m, m[kill][i]);
            }
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < pid.size(); i++) {
            m[ppid[i]].push_back(pid[i]);
        }
        dfs(m, kill);
        return ans;
    }
};

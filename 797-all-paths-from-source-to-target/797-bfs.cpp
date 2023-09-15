class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        while (!q.empty()) {
            int t = q.front().first;
            vector<int> v = q.front().second;
            q.pop();
            for (int x : graph[t]) {
                v.push_back(x);
                if (x == n)
                    ans.push_back(v);
                else
                    q.push({x, v});
                v.pop_back();
            }
        }

        return ans;
    }
};

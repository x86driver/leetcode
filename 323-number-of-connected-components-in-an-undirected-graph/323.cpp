class Solution {
private:
    bool bfs(int start, vector<bool>& visit, const vector<vector<int>>& graph) {
        bool hasVisit = false;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visit[node] = true;
            for (int v : graph[node]) {
                if (visit[v])
                    continue;
                q.push(v);
                hasVisit = true;
            }
        }

        return hasVisit;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visit(n);
        vector<vector<int>> graph(n);
        int ans = 0;
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (visit[i] == false) {
                bfs(i, visit, graph);
                ++ans;
            }
        }

        return ans;
    }
};

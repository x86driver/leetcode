class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty())
            if (n == 1)
                return true;
            else
                return false;
        vector<bool> visit(n);
        vector<unordered_set<int>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        int start = 0;
        queue<int> q;
        q.push(start);
        visit[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int n : graph[node]) {
                if (visit[n]) {
                    return false;
                }
                visit[n] = true;
                q.push(n);
                graph[n].erase(node);
            }
        }

        for (bool v : visit)
            if (!v)
                return false;
        return true;
    }
};

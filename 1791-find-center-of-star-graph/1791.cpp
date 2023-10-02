class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = -1;
        for (const vector<int>& edge : edges) {
            n = max(n, edge[0]);
            n = max(n, edge[1]);
        }
        vector<vector<int>> graph(n + 1);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() == n - 1) {
                return i;
            }
        }

        return -1;
    }
};

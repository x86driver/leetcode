class Solution {
private:
    bool bfs(const vector<vector<int>>& graph, vector<bool>& isVisit, int start) {
        if (isVisit[start]) {
            return false;
        }
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int city = q.front();
            q.pop();
            isVisit[city] = true;
            for (int i = 0; i < graph[city].size(); i++) {
                if (!isVisit[graph[city][i]]) {
                    q.push(graph[city][i]);
                }
            }
        }
        return true;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> graph(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }

        int provinces = 0;
        vector<bool> isVisit(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++) {
            if (bfs(graph, isVisit, i)) {
                ++provinces;
            }
        }
        return provinces;
    }
};

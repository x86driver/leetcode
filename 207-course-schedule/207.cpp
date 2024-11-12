class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses);
        queue<int> q;

        for (const vector<int>& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            graph[u].push_back(v);
        }

        for (const vector<int>& u : graph) {
            for (int v : u) {
                in_degree[v]++;
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int v : graph[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0)
                    q.push(v);
            }
        }

        return result.size() == numCourses;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses);
        for (const vector<int>& pre : prerequisites) {
            int u = pre[1];
            int v = pre[0];
            graph[u].push_back(v);
            in_degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        result.reserve(numCourses);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for (int next : graph[curr]) {
                in_degree[next]--;
                if (in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (result.size() == numCourses)
            return result;
        else
            return {};
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        vector<unordered_set<int>> graph(n);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        int remainNodes = n;
        while (remainNodes > 2) {
            remainNodes -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int target = *graph[leaf].begin();
                graph[target].erase(leaf);
                if (graph[target].size() == 1) {
                    newLeaves.push_back(target);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

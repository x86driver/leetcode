class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int curr, int target) {
        if (curr == target) {
            path.push_back(curr);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(curr);
        for (int i = 0; i < graph[curr].size(); i++) {
            dfs(graph, graph[curr][i], target);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};

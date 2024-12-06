/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, vector<vector<int>>& graph) {
        if (!root)
            return;
        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        if (!root->left && !root->right) {
            graph[root->val].push_back(0);
            return;
        }
        dfs(root->left, graph);
        dfs(root->right, graph);
    }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        vector<vector<int>> graph(1001);
        vector<bool> visit(1001);
        dfs(root, graph);
        queue<int> q;
        q.push(k);
        visit[k] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visit[node] = true;
            for (int v : graph[node]) {
                if (v == 0)
                    return node;
                if (visit[v])
                    continue;
                q.push(v);
            }
        }
        return root->val;
    }
};

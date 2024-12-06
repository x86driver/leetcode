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
    map<int, int> m;
    int count;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        ++m[node->val];
        count = max(count, m[node->val]);
        dfs(node->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        dfs(root);
        vector<int> ans;
        for (const pair<int, int>& p : m) {
            if (p.second == count) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};

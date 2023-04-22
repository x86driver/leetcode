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
    int depth;
    void dfs(TreeNode* root, int d) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            depth = min(depth, d);
            return;
        }
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        depth = 1e5;
        dfs(root, 1);
        return depth;
    }
};

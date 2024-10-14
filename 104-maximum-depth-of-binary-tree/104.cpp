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
    int dfs(TreeNode* node, int level) {
        if (!node) {
            return level;
        }
        int left = dfs(node->left, level + 1);
        int right = dfs(node->right, level + 1);
        return max(left, right);
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};

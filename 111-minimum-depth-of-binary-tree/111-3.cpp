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
    int dfs(TreeNode* node, int depth) {
        if (!node)
            return INT_MAX;
        if (!node->left && !node->right)
            return depth;
        int left = dfs(node->left, depth + 1);
        int right = dfs(node->right, depth + 1);
        return min(left, right);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        return dfs(root, 1);
    }
};

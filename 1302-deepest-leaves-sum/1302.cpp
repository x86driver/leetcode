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
    int calDepth(TreeNode* node, int depth) {
        int left = 0;
        int right = 0;
        if (node->left)
            left = calDepth(node->left, depth + 1);
        if (node->right)
            right = calDepth(node->right, depth + 1);

        ++depth;
        return max(max(left, depth), right);
    }
    int dfs(TreeNode* node, int depth, int targetDepth) {
        int left = 0;
        int right = 0;
        if (node->left)
            left += dfs(node->left, depth + 1, targetDepth);
        if (node->right)
            right += dfs(node->right, depth + 1, targetDepth);

        ++depth;
        if (depth == targetDepth)
            return node->val;
        else
            return left + right;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = calDepth(root, 0);
        return dfs(root, 0, depth);
    }
};

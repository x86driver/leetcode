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
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) {
            return 0;
        }
        int left = dfs(node->left, true);
        int right = dfs(node->right, false);
        if (!node->left && !node->right && isLeft) {
            return node->val + left + right;
        } else {
            return left + right;
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};

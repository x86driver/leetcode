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
    int longest;
    void findPath(TreeNode* node, int len) {
        if (!node)
            return;
        if (node->left && node->left->val - node->val == 1) {
            findPath(node->left, len + 1);
        }
        if (node->right && node->right->val - node->val == 1) {
            findPath(node->right, len + 1);
        }
        longest = max(longest, len);
    }
    void dfs(TreeNode* root) {
        if (!root)
            return;
        findPath(root, 1);
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
    }
public:
    int longestConsecutive(TreeNode* root) {
        longest = 0;
        dfs(root);
        return longest;
    }
};

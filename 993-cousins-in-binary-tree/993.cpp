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
    TreeNode* parent_x;
    TreeNode* parent_y;
    int depth_x;
    int depth_y;
    void dfs(TreeNode* node, int target, int depth, bool is_x) {
        if (!node)
            return;
        if (node->val == target) {
            if (is_x) {
                parent_x = nullptr;
                depth_x = depth - 1;
            } else {
                parent_y = nullptr;
                depth_y = depth - 1;
            }
            return;
        }
        if (node->right && node->right->val == target ||
            node->left && node->left->val == target) {
            if (is_x) {
                parent_x = node;
                depth_x = depth;
            } else {
                parent_y = node;
                depth_y = depth;
            }
            return;
        }
        dfs(node->left, target, depth + 1, is_x);
        dfs(node->right, target, depth + 1, is_x);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, 0, true);
        dfs(root, y, 0, false);
        return (parent_x != parent_y) && (depth_x == depth_y);
    }
};

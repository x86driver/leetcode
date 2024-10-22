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

struct TreeInfo {
    int depth;
    bool isValid;
};

class Solution {
private:
    struct TreeInfo dfs(TreeNode* node, int depth) {
        if (!node) {
            return {.depth = depth, .isValid = true};
        }

        TreeInfo left = dfs(node->left, depth + 1);
        TreeInfo right = dfs(node->right, depth + 1);
        TreeInfo info = {
            .depth = max(left.depth, right.depth),
            .isValid = abs(left.depth - right.depth) <= 1 && left.isValid && right.isValid
        };
        return info;
    }
public:
    bool isBalanced(TreeNode* root) {
        TreeInfo info = dfs(root, 0);
        return info.isValid;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* dfs(TreeNode* node, int target) {
        if (!node)
            return nullptr;
        if (node->val == target)
            return node;
        TreeNode *left = dfs(node->left, target);
        if (left)
            return left;
        TreeNode *right = dfs(node->right, target);
        return right;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target->val);
    }
};

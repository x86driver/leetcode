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
    TreeNode* dfs(TreeNode *cloned, TreeNode *target) {
        if (cloned->val == target->val)
            return cloned;

        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if (cloned->left)
            left = dfs(cloned->left, target);
        if (cloned->right)
            right = dfs(cloned->right, target);

        if (left)
            return left;
        else
            return right;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target);
    }
};

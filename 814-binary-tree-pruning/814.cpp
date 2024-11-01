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
    bool dfs(TreeNode* node) {
        if (!node)
            return true;
        bool left = dfs(node->left);
        bool right = dfs(node->right);
        if (left)
            node->left = nullptr;
        if (right)
            node->right = nullptr;
        return left && right && node->val == 0;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (dfs(root))
            return nullptr;
        else
            return root;
    }
};

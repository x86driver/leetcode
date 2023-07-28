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
    TreeNode *newhead;
    TreeNode *node;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        node->right = new TreeNode(root->val);
        node = node->right;
        dfs(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        newhead = new TreeNode;
        node = newhead;
        dfs(root);
        return newhead->right;
    }
};

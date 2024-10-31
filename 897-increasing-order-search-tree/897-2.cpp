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
    TreeNode ans;
    TreeNode *curr;
    void dfs(TreeNode* node) {
        if (!node)
            return;
        dfs(node->left);
        curr->right = new TreeNode(node->val);
        curr = curr->right;
        dfs(node->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        curr = &ans;
        dfs(root);
        return ans.right;
    }
};

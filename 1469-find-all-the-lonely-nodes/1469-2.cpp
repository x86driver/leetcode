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
    vector<int> ans;
    void dfs(TreeNode *node) {
        if (!node)
            return;
        dfs(node->left);
        dfs(node->right);
        if (node->left && !node->right)
            ans.push_back(node->left->val);
        else if (!node->left && node->right)
            ans.push_back(node->right->val);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

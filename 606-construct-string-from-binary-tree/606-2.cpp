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
    string ans;
    void dfs(TreeNode* node) {
        if (!node)
            return;
        ans += to_string(node->val);
        if (!node->left && node->right) {
            ans += "()";
        }
        if (node->left) {
            ans += '(';
            dfs(node->left);
            ans += ')';
        }

        if (node->right) {
            ans += '(';
            dfs(node->right);
            ans += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

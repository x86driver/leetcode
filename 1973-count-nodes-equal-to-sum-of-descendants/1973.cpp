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
    uint32_t count;
    uint32_t dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if ((left + right) == root->val) {
            ++count;
        }
        return left + right + root->val;
    }
public:
    int equalToDescendants(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};

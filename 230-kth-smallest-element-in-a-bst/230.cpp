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
    int ans;
    int k;
    void dfs(TreeNode* node) {
        if (!node || ans != -1)
            return;

        dfs(node->left);
        if (k == 1 && ans == -1) {
            ans = node->val;
            return;
        }
        --k;
        dfs(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->ans = -1;
        this->k = k;
        dfs(root);
        return this->ans;
    }
};

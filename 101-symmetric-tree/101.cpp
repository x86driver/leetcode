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
    vector<int> left, right;
    void dfs_left(TreeNode* root) {
        if (!root) {
            left.push_back(200);
            return;
        }
        left.push_back(root->val);
        dfs_left(root->right);
        dfs_left(root->left);
    }
    void dfs_right(TreeNode* root) {
        if (!root) {
            right.push_back(200);
            return;
        }
        right.push_back(root->val);
        dfs_right(root->left);
        dfs_right(root->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        dfs_left(root->left);
        dfs_right(root->right);
        return left == right;
    }
};

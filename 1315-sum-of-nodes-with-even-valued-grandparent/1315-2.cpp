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
    int sum;
    void dfs(TreeNode* root, TreeNode* grandparent, TreeNode* parent) {
        if (!root) {
            return;
        }
        if (grandparent && grandparent->val % 2 == 0) {
            sum += root->val;
        }
        dfs(root->left, parent, root);
        dfs(root->right, parent, root);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        dfs(root, nullptr, nullptr);
        return sum;
    }
};

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
    void dfs(TreeNode* node1, TreeNode* node2, int level) {
        if (!node1 || !node2)
            return;
        if (level % 2 == 1) {
            int tmp = node1->val;
            node1->val = node2->val;
            node2->val = tmp;
        }
        dfs(node1->left, node2->right, level + 1);
        dfs(node1->right, node2->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};

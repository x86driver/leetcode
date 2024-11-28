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
    bool adding;
    void dfs(TreeNode* node, int low, int high) {
        if (!node)
            return;
        dfs(node->left, low, high);
        if (node->val == low) {
            adding = true;
        }
        if (adding) {
            sum += node->val;
        }
        if (node->val == high) {
            adding = false;
            return;
        }
        dfs(node->right, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        adding = false;
        dfs(root, low, high);
        return sum;
    }
};

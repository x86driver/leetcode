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
    int getEven(TreeNode* root) {
        int s = 0;
        if (!root)
            return 0;
        if (root->left)
            s += root->left->val;
        if (root->right)
            s += root->right->val;
        return s;
    }
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        if ((root->val % 2) == 0) {
            sum += getEven(root->left);
            sum += getEven(root->right);
        }

        sum += dfs(root->left);
        sum += dfs(root->right);

        return sum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root);
    }
};

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
    int targetSum;
    bool dfs(TreeNode* root, int sum) {
        bool left = false;
        bool right = false;

        if (root->left)
            left = dfs(root->left, sum + root->val);
        if (root->right)
            right = dfs(root->right, sum + root->val);

        if (!root->left && !root->right)
            return sum + root->val == targetSum;
        else
            return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        this->targetSum = targetSum;
        return dfs(root, 0);
    }
};

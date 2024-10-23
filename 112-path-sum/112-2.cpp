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
    int currentSum;
    bool dfs(TreeNode* node, int targetSum) {
        if (!node) {
            return false;
        }
        currentSum += node->val;

        if (currentSum == targetSum && !node->left && !node->right)
            return true;

        bool left = dfs(node->left, targetSum);
        bool right = dfs(node->right, targetSum);
        currentSum -= node->val;

        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        currentSum = 0;
        return dfs(root, targetSum);
    }
};

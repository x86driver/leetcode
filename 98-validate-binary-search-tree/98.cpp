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
struct TreeInfo {
    long minValue;
    long maxValue;
    bool isValid;
};
class Solution {
private:
    TreeInfo dfs(TreeNode* node) {
        if (!node) {
            return {
                .minValue = 2147483648,
                .maxValue = -2147483649,
                .isValid = true
            };
        }
        TreeInfo left = dfs(node->left);
        TreeInfo right = dfs(node->right);
        long value = node->val;
        return {
            .minValue = min(value, min(left.minValue, right.minValue)),
            .maxValue = max(value, max(left.maxValue, right.maxValue)),
            .isValid = left.isValid && right.isValid && left.maxValue < node->val && right.minValue > node->val
        };
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root).isValid;
    }
};

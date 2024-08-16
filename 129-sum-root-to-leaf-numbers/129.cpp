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
    uint64_t tmp;
    void dfs(TreeNode *node) {
        if (!node)
            return;

        tmp += node->val;
        tmp *= 10;
        if (!node->left && !node->right) {
            sum += tmp / 10;
        } else {
            dfs(node->left);
            dfs(node->right);
        }
        tmp /= 10;
        tmp -= node->val;
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        tmp = 0;
        dfs(root);
        return sum;
    }
};

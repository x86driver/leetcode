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
    int count;
    int sum;
};

class Solution {
private:
    int ans;
    TreeInfo dfs(TreeNode* node) {
        TreeInfo left = {.count = 0, .sum = 0};
        TreeInfo right = {.count = 0, .sum = 0};

        if (node->left)
            left = dfs(node->left);
        if (node->right)
            right = dfs(node->right);

        TreeInfo info = {
            .count = left.count + right.count + 1,
            .sum = left.sum + right.sum + node->val
        };

        if (floor(info.sum / info.count) == node->val)
            ++ans;
        return info;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        TreeInfo info = dfs(root);
        return ans;
    }
};

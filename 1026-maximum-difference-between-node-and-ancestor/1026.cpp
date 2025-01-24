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
    int diff;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {10e5+1, -1};
        }
        auto [minl, maxl] = dfs(root->left);
        auto [minr, maxr] = dfs(root->right);
        int maximum = max(max(maxl, maxr), root->val);
        int minimum = min(min(minl, minr), root->val);
        diff = max(diff, max(abs(maximum - root->val), abs(root->val - minimum)));
        return {minimum, maximum};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        diff = 0;
        dfs(root);
        return diff;
    }
};

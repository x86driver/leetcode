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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        auto max_iter = max_element(nums.begin(), nums.end());
        vector<int> left(nums.begin(), max_iter);
        vector<int> right(max_iter + 1, nums.end());
        TreeNode *curr = new TreeNode(*max_iter);
        curr->left = constructMaximumBinaryTree(left);
        curr->right = constructMaximumBinaryTree(right);
        return curr;
    }
};

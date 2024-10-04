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
        if (nums.empty()) {
            return nullptr;
        }
        auto max_it = max_element(nums.begin(), nums.end());
        int max_distance = distance(nums.begin(), max_it);
        TreeNode* head = new TreeNode(*max_it);
        vector<int> left(nums.begin(), nums.begin() + max_distance);
        vector<int> right(nums.begin() + max_distance + 1, nums.end());
        head->left = constructMaximumBinaryTree(left);
        head->right = constructMaximumBinaryTree(right);
        return head;
    }
};

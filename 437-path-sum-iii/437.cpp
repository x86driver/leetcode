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
    int target;
    int ans;
    void traverse(TreeNode* root, void(Solution::*func)(TreeNode *, int64_t)) {
        if (!root)
            return;
        (this->*func)(root, target);
        traverse(root->left, func);
        traverse(root->right, func);
    }
    void checkSum(TreeNode* node, int64_t target) {
        if (!node)
            return;

        target -= node->val;
        if (target == 0) {
            ++ans;
        }
        checkSum(node->left, target);
        checkSum(node->right, target);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        ans = 0;
        traverse(root, &Solution::checkSum);
        return ans;
    }
};

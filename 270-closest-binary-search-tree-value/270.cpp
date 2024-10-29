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
    int ans;
    double diff;
    void bst(TreeNode* node, double target) {
        if (!node)
            return;
        if (node->val == target) {
            diff = 0;
            ans = node->val;
            return;
        }
        double tmpdiff = abs(target - node->val);
        if (tmpdiff < diff || (tmpdiff == diff && node->val < ans)) {
            diff = tmpdiff;
            ans = node->val;
        }
        if (node->val > target) {
            bst(node->left, target);
        } else {
            bst(node->right, target);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        ans = INT_MAX;
        diff = numeric_limits<double>::max();
        bst(root, target);
        return ans;
    }
};

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
    vector<vector<int>> ans;
    vector<int> tmp;
    void bt(TreeNode *node, int targetSum, int currentSum) {
        if (!node)
            return;
        currentSum += node->val;
        tmp.push_back(node->val);
        if (currentSum == targetSum && !node->left && !node->right) {
            ans.push_back(tmp);
        } else {
            bt(node->left, targetSum, currentSum);
            bt(node->right, targetSum, currentSum);
        }
        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        bt(root, targetSum, 0);
        return ans;
    }
};

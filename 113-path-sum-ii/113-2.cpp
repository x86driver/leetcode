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
    vector<vector<int>> ans;
    vector<int> tmp;
    int currSum;
    void dfs(TreeNode* node, int targetSum) {
        currSum += node->val;
        tmp.push_back(node->val);
        if (!node->left && !node->right && currSum == targetSum) {
            ans.push_back(tmp);
        }
        if (node->left)
            dfs(node->left, targetSum);
        if (node->right)
            dfs(node->right, targetSum);
        currSum -= node->val;
        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};
        currSum = 0;
        dfs(root, targetSum);
        return ans;
    }
};


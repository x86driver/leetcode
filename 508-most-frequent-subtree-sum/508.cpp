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
    int maxCount;
    unordered_map<int, int> m;
    int sumTree(TreeNode* node) {
        if (!node)
            return 0;
        int left = sumTree(node->left);
        int right = sumTree(node->right);
        return left + right + node->val;
    }
    void dfs(TreeNode* root) {
        if (!root)
            return;
        int sum = sumTree(root);
        ++m[sum];
        maxCount = max(maxCount, m[sum]);
        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxCount = 0;
        dfs(root);
        vector<int> ans;
        for (const auto& [sum, count] : m) {
            if (count == maxCount) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};

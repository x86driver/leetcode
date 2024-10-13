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
    vector<int> tmp;
    bool dfs(TreeNode* node) {
        if (!node)
            return true;
        if (!node->left && !node->right) {
            tmp.push_back(node->val);
            return true;
        }
        if (dfs(node->left)) {
            node->left = nullptr;
        }
        if (dfs(node->right)) {
            node->right = nullptr;
        }
        return false;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while (root) {
            if (dfs(root))
                root = nullptr;
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};

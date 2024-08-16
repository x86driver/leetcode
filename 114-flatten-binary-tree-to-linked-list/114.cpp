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
    void dfs(TreeNode *node) {
        if (!node)
            return;
        tmp.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
public:
    void flatten(TreeNode* root) {
        dfs(root);
        TreeNode *node = root;
        for (int i = 0; i < tmp.size(); ++i) {
            node->val = tmp[i];
            node->left = nullptr;
            if (i != (tmp.size() - 1))
                if (!node->right)
                    node->right = new TreeNode;
            node = node->right;
        }
    }
};

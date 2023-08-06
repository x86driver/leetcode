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
    vector<int> leaves;
    void find(TreeNode* node) {
        if (!node)
            return;
        if (node->left) {
            if (node->left->left == nullptr && node->left->right == nullptr) {
                leaves.push_back(node->left->val);
                delete node->left;
                node->left = nullptr;
            }
        }
        if (node->right) {
            if (node->right->left == nullptr && node->right->right == nullptr) {
                leaves.push_back(node->right->val);
                delete node->right;
                node->right = nullptr;
            }
        }
        find(node->left);
        find(node->right);
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while (root->left || root->right) {
            find(root);
            ans.push_back(move(leaves));
        }
        ans.push_back({root->val});
        return ans;
    }
};

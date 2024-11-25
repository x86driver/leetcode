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
    bool dfs(TreeNode* root, TreeNode* node, int k) {
        if (!root || !node)
            return false;
        int diff = k - node->val;
        if (diff != node->val) {
            TreeNode* curr = root;
            while (curr) {
                if (diff == curr->val)
                    return true;
                if (diff > curr->val)
                    curr = curr->right;
                else
                    curr = curr->left;
            }
        }
        bool left = dfs(root, node->left, k);
        bool right = dfs(root, node->right, k);
        return left || right;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
};

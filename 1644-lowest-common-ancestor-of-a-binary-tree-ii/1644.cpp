/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeInfo {
    TreeNode* node_p;
    TreeNode* node_q;
    TreeNode* ancestor;
};

class Solution {
public:
    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q, TreeInfo* info) {
        if (!root)
            return nullptr;

        if (root == p) {
            info->node_p = root;
            if (!info->ancestor)
                info->ancestor = root;
        } else if (root == q) {
            info->node_q = root;
            if (!info->ancestor)
                info->ancestor = root;
        }

        TreeNode* left = traverse(root->left, p, q, info);
        TreeNode* right = traverse(root->right, p, q, info);

        if (left && right || root == p || root == q) {
            info->ancestor = root;
            return root;
        }
        if (!left)
            return right;
        if (!right)
            return left;
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeInfo info = {.node_p = nullptr, .node_q = nullptr};
        TreeNode *ans = traverse(root, p, q, &info);
        if (info.ancestor && info.node_p && info.node_q)
            return info.ancestor;
        return nullptr;
    }
};

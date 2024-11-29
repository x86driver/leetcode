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
struct TreeInfo {
    TreeNode *node;
    int depth;
};

class Solution {
private:
    int maxDepth;
    TreeInfo dfs(TreeNode* node, TreeNode* parent, int depth) {
        if (!node)
            return {
                .node = nullptr,
                .depth = 0
            };
        TreeInfo left = dfs(node->left, node, depth + 1);
        TreeInfo right = dfs(node->right, node, depth + 1);
        TreeInfo ret;
        if (left.node == nullptr && right.node == nullptr) {
            ret.depth = depth;
            ret.node = node;
        } else if (left.depth == right.depth && left.depth > depth) {
            ret.depth = left.depth;
            ret.node = node;
        } else if (left.depth > right.depth) {
            ret.depth = left.depth;
            ret.node = left.node;
        } else {
            ret.depth = right.depth;
            ret.node = right.node;
        }
        return ret;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth = 0;
        return dfs(root, root, 0).node;
    }
};

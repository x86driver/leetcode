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
    int computeDepth(TreeNode* node) {
        int d = 0;
        while (node->left) {
            ++d;
            node = node->left;
        }
        return d;
    }
    bool exist(TreeNode* node, int d, int idx) {
        int left = 0;
        int right = pow(2, d) - 1;
        for (int i = 0; i < d; ++i) {
            int pivot = left + (right - left) / 2;
            if (idx <= pivot) {
                node = node->left;
                right = pivot;
            } else {
                node = node->right;
                left = pivot + 1;
            }
        }
        return node;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int depth = computeDepth(root);
        if (depth == 0)
            return 1;

        int left = 1;
        int right = pow(2, depth) - 1;

        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (exist(root, depth, pivot)) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }

        return pow(2, depth) - 1 + left;
    }
};

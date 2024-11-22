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
    int maximum;
    int minimum;
    int nodes;
    bool isBST;
};

class Solution {
private:
    int ans;
    TreeInfo dfs(TreeNode* node) {
        if (!node) {
            return {
                .maximum = -INT_MAX,
                .minimum = INT_MAX,
                .nodes = 0,
                .isBST = true
            };
        }
        TreeInfo left = dfs(node->left);
        TreeInfo right = dfs(node->right);
        int maximum = max(node->val, max(left.maximum, right.maximum));
        int minimum = min(node->val, min(left.minimum, right.minimum));
        bool isBST = false;
        int nodes = 1;
        if (left.isBST && left.maximum < node->val &&
            right.isBST && right.minimum > node->val) {
                isBST = true;
                nodes += left.nodes + right.nodes;
                ans = max(ans, nodes);
        }

        return {
            .maximum = maximum,
            .minimum = minimum,
            .nodes = nodes,
            .isBST = isBST
        };
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};

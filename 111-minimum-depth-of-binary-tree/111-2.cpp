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
    vector<int> leafs;
    int dfs(TreeNode* node, int depth) {
        if (!node) {
            return depth;
        }
        int left = dfs(node->left, depth + 1);
        int right = dfs(node->right, depth + 1);
        if (!node->left && !node->right) {
            leafs.push_back(depth);
            return depth;
        }
        return min(left, right);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, 1);
        return *min_element(leafs.begin(), leafs.end());
    }
};

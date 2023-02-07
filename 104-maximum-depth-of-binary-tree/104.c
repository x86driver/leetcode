/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a, b) ((a) < (b) ? (b) : (a))

int dfs(struct TreeNode* root, int depth) {
    if (root == NULL)
        return depth;
    int left = dfs(root->left, depth + 1);
    int right = dfs(root->right, depth + 1);
    return max(left, right);
}

int maxDepth(struct TreeNode* root){
    return dfs(root, 0);
}

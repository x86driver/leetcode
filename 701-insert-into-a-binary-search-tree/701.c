/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int val) {
    if (val < root->val) {
        if (root->left) {
            dfs(root->left, val);
        } else {
            root->left = calloc(1, sizeof(struct TreeNode));
            root->left->val = val;
            return;
        }
    } else {
        if (root->right) {
            dfs(root->right, val);
        } else {
            root->right = calloc(1, sizeof(struct TreeNode));
            root->right->val = val;
            return;
        }
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (!root) {
        struct TreeNode* node = calloc(1, sizeof(struct TreeNode));
        node->val = val;
        return node;
    }

    dfs(root, val);
    return root;
}

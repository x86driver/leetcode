/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    struct TreeNode *node = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
    if (!node) {
        perror("calloc tree node");
        exit(1);
    }
    node->val = root1->val + root2->val;
    node->left = mergeTrees(root1->left, root2->left);
    node->right = mergeTrees(root1->right, root2->right);
    return node;
}

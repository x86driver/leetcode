/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))

struct Info {
    bool isValid;
    long long minVal;
    long long maxVal;
};

struct Info dfs(struct TreeNode* root) {
    if (root == NULL) {
        struct Info info = {.isValid = true, .minVal = LLONG_MAX, .maxVal = -LLONG_MAX};
        return info;
    }

    struct Info left = dfs(root->left);
    struct Info right = dfs(root->right);
    struct Info info;
    info.isValid = left.isValid && right.isValid && left.maxVal < root->val &&  right.minVal > root->val;
    info.minVal = min(root->val, left.minVal);
    info.maxVal = max(root->val, right.maxVal);
    return info;
}

bool isValidBST(struct TreeNode* root){
    struct Info info = dfs(root);
    return info.isValid;
}

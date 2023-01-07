/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define PRIME (1021)
#define HashSize (PRIME)

int HashSet[HashSize];

void AddToHashSet(int val) {
    HashSet[val] = val;
}

int HashSetFind(int val) {
    return HashSet[val];
}

void InitHashSet(int *to_delete, int to_deleteSize) {
    bzero(&HashSet, sizeof(HashSet));
    for (int i = 0; i < to_deleteSize; ++i)
        AddToHashSet(to_delete[i]);
}

bool dfs(struct TreeNode *node, struct TreeNode **remain, int *remainIndex) {
    if (node == NULL) {
        return false;
    }

    if (dfs(node->left, remain, remainIndex))
        node->left = NULL;
    if (dfs(node->right, remain, remainIndex))
        node->right = NULL;

    if (HashSetFind(node->val) != 0) {
        if (node->left) {
            remain[(*remainIndex)++] = node->left;
        }
        if (node->right) {
            remain[(*remainIndex)++] = node->right;
        }
        return true;
    }

    return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){

    InitHashSet(to_delete, to_deleteSize);
    struct TreeNode *remain[1000];
    bzero(&remain, sizeof(remain));
    *returnSize = 0;

    if (dfs(root, remain, returnSize) == false) {
        remain[(*returnSize)++] = root;
    }

    struct TreeNode **ret = (struct TreeNode**)calloc(*returnSize, sizeof(struct TreeNode*));
    if (ret == NULL) {
        perror("calloc");
        return NULL;
    }

    memcpy(ret, remain, (*returnSize) * sizeof(struct TreeNode*));

    return ret;
}

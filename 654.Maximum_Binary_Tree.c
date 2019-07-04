#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    if (numsSize <= 0) {
        free(nums);
        return NULL;
    }

    int max = 0;
    int index = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > max) {
            max = nums[i];
            index = i;
        }
    }

    struct TreeNode* node = (struct TreeNode*)calloc(1, sizeof(*node));
    node->val = max;

    int *left_number = (int*)calloc(index, sizeof(int));
    for (int i = 0; i < index; ++i) {
        left_number[i] = nums[i];
    }

    int *right_number = (int*)calloc(numsSize - index - 1, sizeof(int));
    for (int i = index + 1; i < numsSize; ++i) {
        right_number[i - index - 1] = nums[i];
    }

    free(nums);
    node->left = constructMaximumBinaryTree(left_number, index);
    node->right = constructMaximumBinaryTree(right_number, numsSize - index - 1);

    return node;
}

void traverse(struct TreeNode *node) {
    printf("%d\n", node->val);
    if (node->left) {
        printf(" / ");
        traverse(node->left);
    }

    if (node->right) {
        printf(" \\ ");
        traverse(node->right);
    }

    if (!node->left && !node->right) {
        printf("\n\n");
    }
}

void free_node(struct TreeNode *node) {
    if (node->left) {
        free_node(node->left);
    }

    if (node->right) {
        free_node(node->right);
    }

    free(node);
}

int main() {
    int n[] = {3, 2, 1, 6, 0, 5};
    int numsSize = sizeof(n) / sizeof(int);
    int *nums = (int*)calloc(numsSize, sizeof(int));
    memcpy(nums, n, sizeof(n));
    struct TreeNode *head = constructMaximumBinaryTree(nums, numsSize);
    traverse(head);
    free_node(head);
    return 0;
}

#pragma once

typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

void print_ascii_tree(TreeNode * t);

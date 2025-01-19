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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level % 2 == 1) {
                vector<TreeNode*> oddNodes;
                oddNodes.reserve(size);
                for (int i = 0; i < size; ++i) {
                    TreeNode* t = q.front();
                    q.pop();
                    oddNodes.push_back(t);
                    if (t->left) {
                        q.push(t->left);
                    }
                    if (t->right) {
                        q.push(t->right);
                    }
                }
                for (int i = 0; i < size / 2; ++i) {
                    swap(oddNodes[i]->val, oddNodes[size - i - 1]->val);
                }
            } else {
                for (int i = 0; i < size; ++i) {
                    TreeNode* t = q.front();
                    q.pop();
                    if (t->left) {
                        q.push(t->left);
                    }
                    if (t->right) {
                        q.push(t->right);
                    }
                }
            }
            ++level;
        }
        return root;
    }
};

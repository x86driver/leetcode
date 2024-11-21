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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        bool canExit = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (level == depth - 1) {
                    TreeNode* tmpLeft = node->left;
                    TreeNode* tmpRight = node->right;
                    node->left = new TreeNode(val, tmpLeft, nullptr);
                    node->right = new TreeNode(val, nullptr, tmpRight);
                    canExit = true;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (canExit)
                break;
            ++level;
        }
        return root;
    }
};

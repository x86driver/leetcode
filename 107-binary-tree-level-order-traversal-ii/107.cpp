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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<vector<int>> dq;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            vector<int> tmp;
            for (int i = 0; i < q_size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            dq.push_front(tmp);
        }
        vector<vector<int>> ans(dq.begin(), dq.end());
        return ans;
    }
};

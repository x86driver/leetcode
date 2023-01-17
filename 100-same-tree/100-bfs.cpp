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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p)
            return !q;
        if (!q)
            return !p;
        if (p->val != q->val)
            return false;

        vector<int> ptree = bfs(p);
        vector<int> qtree = bfs(q);

        if (ptree.size() != qtree.size())
            return false;

        for (int i = 0; i < ptree.size(); ++i)
            if (ptree[i] != qtree[i])
                return false;

        return true;
    }
private:
    vector<int> bfs(TreeNode* head) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(head);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                result.push_back(node->left->val);
            } else {
                result.push_back(-100000);
            }
            if (node->right) {
                q.push(node->right);
                result.push_back(node->right->val);
            } else {
                result.push_back(-100000);
            }
        }

        return result;
    }
};

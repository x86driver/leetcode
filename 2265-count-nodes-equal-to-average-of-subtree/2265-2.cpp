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
private:
    int ans;
    int average(TreeNode* node) {
        int count = 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            ++count;
            sum += tmp->val;
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        return sum / count;
    }
    void dfs(TreeNode* node) {
        if (!node)
            return;
        int ave = average(node);
        if (ave == node->val)
            ++ans;
        dfs(node->left);
        dfs(node->right);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};

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
    map<int, vector<TreeNode*>> m;
    int bfs(TreeNode* node, int level) {
        int max_level = level;
        queue<pair<TreeNode*, int>> q;
        q.push({node, level});
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            m[p.second].push_back(p.first);
            max_level = max(max_level, p.second);
            if (p.first->left)
                q.push({p.first->left, p.second + 1});
            if (p.first->right)
                q.push({p.first->right, p.second + 1});
        }
        return max_level;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        int levels = bfs(root, 0);
        vector<vector<int>> ans;
        for (int i = 0; i <= levels; ++i) {
            vector<int> tmp;
            vector<TreeNode*> &nodes = m[i];
            for (TreeNode* node : nodes)
                tmp.push_back(node->val);
            ans.push_back(tmp);
        }
        return ans;
    }
};

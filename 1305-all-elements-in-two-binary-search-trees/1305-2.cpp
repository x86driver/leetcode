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
    void dfs(TreeNode* root, vector<int>& tree) {
        if (!root) {
            return;
        }
        dfs(root->left, tree);
        tree.push_back(root->val);
        dfs(root->right, tree);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2;
        dfs(root1, tree1);
        dfs(root2, tree2);
        vector<int> ans;
        int i1 = 0, i2 = 0;
        while (i1 < tree1.size() && i2 < tree2.size()) {
            if (tree1[i1] <= tree2[i2]) {
                ans.push_back(tree1[i1]);
                ++i1;
            } else {
                ans.push_back(tree2[i2]);
                ++i2;
            }
        }
        while (i1 < tree1.size()) {
            ans.push_back(tree1[i1++]);
        }
        while (i2 < tree2.size()) {
            ans.push_back(tree2[i2++]);
        }
        return ans;
    }
};

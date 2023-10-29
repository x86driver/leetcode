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
    vector<int> num;
    int ans;
    void dfs(TreeNode* root) {
        if (root->left) {
            num.push_back(root->left->val);
            dfs(root->left);
            num.pop_back();
        }
        if (root->right) {
            num.push_back(root->right->val);
            dfs(root->right);
            num.pop_back();
        }
        if (!root->left && !root->right) {
            int tmp = 0;
            for (int n : num) {
                tmp <<= 1;
                tmp += n;
            }
            ans += tmp;
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        num.push_back(root->val);
        dfs(root);
        return ans;
    }
};

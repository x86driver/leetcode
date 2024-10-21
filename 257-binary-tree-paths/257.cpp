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
    vector<string> ans;
    vector<int> tmp;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        tmp.push_back(node->val);
        if (!node->left && !node->right) {
            string str;
            for (int x : tmp) {
                str += to_string(x);
                str += "->";
            }
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
        } else {
            dfs(node->left);
            dfs(node->right);
        }
        tmp.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

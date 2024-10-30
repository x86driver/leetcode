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
struct TreeInfo {
    int uni;
    bool isSame;
};

class Solution {
private:
    int ans;
    TreeInfo dfs(TreeNode* node) {
        if (!node) {
            return {
                .uni = -2000,
                .isSame = true
            };
        }
        TreeInfo left = dfs(node->left);
        TreeInfo right = dfs(node->right);
        int uni = node->val;
        bool isSame = false;
        if (left.uni == -2000 && right.uni == -2000) {
            isSame = true;
        }
        if (left.uni == -2000 && right.uni == uni && right.isSame) {
            isSame = true;
        }
        if (right.uni == -2000 && left.uni == uni && left.isSame) {
            isSame = true;
        }
        if (left.isSame && right.isSame && left.uni == right.uni && left.uni == uni) {
            isSame = true;
        }
        if (isSame) {
            ++ans;
        }
        //cout << "Node : " << node->val << ", uni: " << uni << ", isSame: " << isSame << endl;
        return {
            .uni = uni,
            .isSame = isSame
        };
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};

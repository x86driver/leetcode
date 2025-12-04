/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string str;
    void dfs(RopeTreeNode* root) {
        if (!root) {
            return;
        }
        if (root->len == 0) {
            str += root->val;
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        // 把4種情況考慮
        // 左邊是數字, 右邊是文字
        // 左邊是文字, 右邊是數字
        // 左右都是數字
        // 左右都是文字
        dfs(root);
        return str[k - 1];
    }
};

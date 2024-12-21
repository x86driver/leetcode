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

struct NodeInfo {
    NodeInfo() : leftmost(UINT64_MAX), rightmost(0) { }
    uint64_t leftmost;
    uint64_t rightmost;
};

class Solution {
private:
    uint64_t maxWidth;
    unordered_map<int, NodeInfo> nodes;
    void dfs(TreeNode* root, int level, uint64_t nth) {
        if (!root) {
            return;
        }
        nodes[level].leftmost = min(nodes[level].leftmost, nth);
        nodes[level].rightmost = max(nodes[level].rightmost, nth);
        //cout << root->val << ", level: " << level << ", 第 " << nth << " 個, ";
        //cout << "最左邊: " << nodes[level].leftmost << ", 最右邊: " << nodes[level].rightmost << ", 相差: " << nodes[level].rightmost - nodes[level].leftmost + 1 << ", 目前max: " << maxWidth << endl;
        maxWidth = max(maxWidth, (nodes[level].rightmost - nodes[level].leftmost) + 1);
        dfs(root->left, level + 1, nth * 2);
        dfs(root->right, level + 1, nth * 2 + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        maxWidth = 0;
        dfs(root, 0, 0);
        return maxWidth;
    }
};

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
    vector<TreeNode*> candidate;
    void findSubtree(TreeNode* root, int val) {
        if (!root)
            return;
        if (root->val == val)
            candidate.push_back(root);
        findSubtree(root->left, val);
        findSubtree(root->right, val);
    }
    bool compareSubtree(TreeNode *nodea, TreeNode *nodeb) {
        if (nodea && !nodeb)
            return false;
        if (!nodea && nodeb)
            return false;
        if (!nodea && !nodeb)
            return true;
        if (nodea->val != nodeb->val)
            return false;
        bool left = compareSubtree(nodea->left, nodeb->left);
        bool right = compareSubtree(nodea->right, nodeb->right);
        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        findSubtree(root, subRoot->val);
        for (TreeNode *node : candidate) {
            if (compareSubtree(node, subRoot))
                return true;
        }
        return false;
    }
};

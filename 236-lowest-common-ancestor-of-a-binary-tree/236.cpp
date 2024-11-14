/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool traverse(TreeNode* root, vector<TreeNode*>& path, int target) {
        if (!root)
            return false;
        path.push_back(root);
        if (root->val == target)
            return true;
        bool left = traverse(root->left, path, target);
        if (left)
            return true;
        bool right = traverse(root->right, path, target);
        if (!right)
            path.pop_back();
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        traverse(root, pathP, p->val);
        traverse(root, pathQ, q->val);

        reverse(pathP.begin(), pathP.end());
        reverse(pathQ.begin(), pathQ.end());

        for (TreeNode* nodeP : pathP) {
            for (TreeNode* nodeQ : pathQ) {
                if (nodeP == nodeQ)
                    return nodeP;
            }
        }

        return nullptr;
    }
};

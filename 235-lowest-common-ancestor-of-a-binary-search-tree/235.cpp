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
    int search(TreeNode* root, int target, vector<TreeNode*>& list) {
        int count = 0;
        if (!root)
            return count;

        TreeNode* curr = root;
        while (curr) {
            list.push_back(curr);
            ++count;
            if (curr->val == target)
                return count;
            if (curr->val > target)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return count;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> plist, qlist;
        int a = search(root, p->val, plist);
        int b = search(root, q->val, qlist);
        if (a > b)
            swap(plist, qlist);

        for (int i = plist.size() - 1; i >= 0; i--) {
            for (int j = qlist.size() - 1; j >= 0; j--) {
                if (plist[i] == qlist[j])
                    return plist[i];
            }
        }
        return nullptr;
    }
};

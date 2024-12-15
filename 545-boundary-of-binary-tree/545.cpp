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
    vector<int> left;
    vector<int> right;
    vector<int> leaves;
    void dfsLeaves(TreeNode* root) {
        if (!root) {
            return;
        }
        dfsLeaves(root->left);
        dfsLeaves(root->right);
        if (!root->left && !root->right) {
            cout << root->val << " ";
            leaves.push_back(root->val);
        } else {
            cout << "[" << root->val << "] ";
        }
    }
    bool dfsRight(TreeNode* root) {
        if (!root) {
            return false;
        }
        if (root->val == leaves.back() && !root->left && !root->right) {
            cout << " 遇到 " << root->val << " 停止!" << endl;
            return true;
        }
        right.push_back(root->val);
        cout << root->val << " ";
        if (dfsRight(root->right)) {
            return true;
        }
        if (dfsRight(root->left)) {
            return true;
        }
        return false;
    }
    bool dfsLeft(TreeNode* root) {
        if (!root) {
            return false;
        }
        if (root->val == leaves.front() && !root->left && !root->right) {
            cout << "遇到 " << root->val << " 停止!" << endl;
            return true;
        }
        left.push_back(root->val);
        cout << root->val << " ";
        if (dfsLeft(root->left)) {
            return true;
        }
        if (dfsLeft(root->right)) {
            return true;
        }
        return false;
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) {
            return {root->val};
        }
        dfsLeaves(root);
        cout << endl << "=== left ===" << endl;
        left.push_back(root->val);
        dfsLeft(root->left);
        cout << endl << "=== right ===" << endl;
        dfsRight(root->right);
        
        cout << endl;
        cout << "array:" << endl;
        for (int l : left) cout << l << " ";
        cout << endl;
        for (int b : leaves) cout << b << " ";
        cout << endl;
        for (int r : right) cout << r << " ";

        left.insert(left.end(),
                    make_move_iterator(leaves.begin()),
                    make_move_iterator(leaves.end()));
        reverse(right.begin(), right.end());
        left.insert(left.end(),
                    make_move_iterator(right.begin()),
                    make_move_iterator(right.end()));
        return left;
    }
};

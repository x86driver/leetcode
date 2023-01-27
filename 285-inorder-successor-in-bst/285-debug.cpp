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
    vector<TreeNode*> nodes;
    int diff;
    TreeNode* candidate;
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p) {
        if (root->val == p->val) {
            if (root->right) {
                TreeNode* node = root->right;
                while (node->left) {
                    node = node->left;
                }
                cout << "Found successor: " << node->val << endl;
                return node;
            } else {
                cout << "Parents: ";
                for (TreeNode* node : nodes) {
                    cout << node->val << " ";
                }
                cout << endl;
                if (candidate) {
                    cout << "Answer: " << candidate->val << endl;
                    return candidate;
                }

                cout << "NULL Answer!" << endl;
                return nullptr;
            }
        } else if (root->val > p->val) { // left
            nodes.push_back(root);
            if ((root->val - p->val) < diff) {
                diff = root->val - p->val;
                candidate = root;
            }
            if (root->left)
                return dfs(root->left, p);
            else
                cout << "左邊空節點, 沒找到" << endl;
        } else if (root->val < p->val) {
            if (root->right)
                return dfs(root->right, p);
            else
                cout << "右邊空節點, 沒找到" << endl;
        }

        return nullptr;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        diff = 1e6;
        candidate = nullptr;
        return dfs(root, p);
    }
};

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
    vector<int> vec1, vec2;
    void find(TreeNode* node, vector<int>& vec) {
        if (!node)
            return;
        find(node->left, vec);
        vec.push_back(node->val);
        find(node->right, vec);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        find(root1, vec1);
        find(root2, vec2);
        vector<int> ans(vec1.size() + vec2.size());
        int i = 0;
        int j = 0;
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] <= vec2[j]) {
                ans[i + j] = vec1[i];
                ++i;
            } else {
                ans[i + j] = vec2[j];
                ++j;
            }
        }

        while (i < vec1.size()) {
            ans[i + j] = vec1[i];
            ++i;
        }

        while (j < vec2.size()) {
            ans[i + j] = vec2[j];
            ++j;
        }

        return ans;
    }
};

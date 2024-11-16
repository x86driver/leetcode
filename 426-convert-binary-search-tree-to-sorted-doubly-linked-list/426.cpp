/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    vector<Node*> m;
    void dfs(Node* node) {
        if (!node)
            return;
        dfs(node->left);
        m[node->val + 1000] = node;
        dfs(node->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;
        m.resize(2001);
        dfs(root);
        Node* ans = nullptr;
        Node* curr = nullptr;
        int i = 0;
        for (i = 0; i < m.size(); ++i) {
            if (m[i] != nullptr) {
                ans = curr = m[i];
                break;
            }
        }
        for (; i < m.size(); ++i) {
            if (m[i] != nullptr) {
                curr->right = m[i];
                m[i]->left = curr;
                curr = m[i];
            }
        }
        curr->right = ans;
        ans->left = curr;
        return ans;
    }
};

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
private:
    unordered_map<Node*, NodeCopy*> m;
    NodeCopy* dfs(Node* root) {
        if (!root)
            return nullptr;
        NodeCopy* node = new NodeCopy(root->val);
        m[root] = node;
        node->left = dfs(root->left);
        node->right = dfs(root->right);
        return node;
    }
    void deep(Node* root, NodeCopy* node) {
        if (!root)
            return;
        if (root->random) {
            node->random = m[root->random];
        }
        deep(root->left, node->left);
        deep(root->right, node->right);
    }
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy *node = dfs(root);
        deep(root, node);
        return node;
    }
};

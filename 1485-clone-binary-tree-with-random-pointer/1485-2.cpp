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
    void dfs(Node* root, NodeCopy* nodeCopy, unordered_map<Node*, NodeCopy*>& m) {
        if (!root) {
            return;
        }
        if (root->left) {
            nodeCopy->left = new NodeCopy;
            m[root->left] = nodeCopy->left;
        } else {
            nodeCopy->left = nullptr;
        }
        if (root->right) {
            nodeCopy->right = new NodeCopy;
            m[root->right] = nodeCopy->right;
        } else {
            nodeCopy->right = nullptr;
        }
        dfs(root->left, nodeCopy->left, m);
        dfs(root->right, nodeCopy->right, m);

        nodeCopy->val = root->val;
    }
    void connect(Node* root, NodeCopy* nodeCopy, unordered_map<Node*, NodeCopy*>& m) {
        if (!root) {
            return;
        }
        if (root->random) {
            nodeCopy->random = m[root->random];
        }
        connect(root->left, nodeCopy->left, m);
        connect(root->right, nodeCopy->right, m);
    }
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> m;
        if (!root) {
            return nullptr;
        }
        NodeCopy* nodeCopy = new NodeCopy(root->val);
        m[root] = nodeCopy;
        dfs(root, nodeCopy, m);
        connect(root, nodeCopy, m);
        return nodeCopy;
    }
};

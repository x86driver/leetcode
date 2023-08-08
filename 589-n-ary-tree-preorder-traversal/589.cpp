/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;
    void dfs(Node* node) {
        if (!node)
            return;
        ans.push_back(node->val);
        for (Node* n : node->children) {
            dfs(n);
        }
    }
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};

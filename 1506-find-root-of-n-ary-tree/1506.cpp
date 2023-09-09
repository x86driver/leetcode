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
    int dfs(Node* node) {
        if (!node)
            return 0;
        int count = 0;
        for (Node *child : node->children)
            count += dfs(child);
        return count + 1;
    }
public:
    Node* findRoot(vector<Node*> tree) {
        for (Node* n : tree) {
            if (dfs(n) == tree.size())
                return n;
        }
        return nullptr;
    }
};

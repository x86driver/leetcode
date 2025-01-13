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
    unordered_map<int, int> m;
    int dfs(Node* node) {
        if (!node) {
            return 0;
        }
        int total = 1;
        for (Node* child : node->children) {
            if (m.find(child->val) != m.end()) {
                total += m[child->val];
            } else {
                total += dfs(child);
            }
        }
        m[node->val] = total;
        return total;
    }
public:
    Node* findRoot(vector<Node*> tree) {
        for (Node* n : tree) {
            if (m.find(n->val) != m.end()) {
                continue;
            }
            if (dfs(n) == tree.size()) {
                return n;
            }
        }
        return nullptr;
    }
};

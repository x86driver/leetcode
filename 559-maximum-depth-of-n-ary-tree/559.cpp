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
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            Node *curr = q.front().first;
            int level = q.front().second;
            ans = max(ans, level);
            q.pop();
            for (Node *node : curr->children) {
                q.push({node, level + 1});
            }
        }
        return ans;
    }
};

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
    Node* cloneTree(Node* root) {
        if (!root)
            return nullptr;
        Node *head = new Node(root->val);
        queue<Node*> q;
        q.push(root);
        queue<Node*> cloned;
        cloned.push(head);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node *n = q.front();
                q.pop();
                Node *cl = cloned.front();
                cloned.pop();
                for (int j = 0; j < n->children.size(); ++j) {
                    q.push(n->children[j]);
                    Node *tmp = new Node(n->children[j]->val);
                    cl->children.push_back(tmp);
                    cloned.push(tmp);
                }
            }
        }

        return head;
    }
};

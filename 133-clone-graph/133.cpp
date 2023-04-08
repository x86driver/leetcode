/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        map<int, Node*> m;
        map<int, Node*> cm; // cloned map
        m[node->val] = node;
        Node *ans = new Node(node->val);
        cm[ans->val] = ans;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            Node *cloned = cm[curr->val];

            for (Node * neighbor : curr->neighbors) {
                if (m.find(neighbor->val) == m.end()) {
                    q.push(neighbor);
                    m[neighbor->val] = neighbor;
                    Node *cloned_neighbor = new Node(neighbor->val);
                    cm[cloned_neighbor->val] = cloned_neighbor;
                    cloned->neighbors.push_back(cloned_neighbor);
                } else {
                    cloned->neighbors.push_back(cm[neighbor->val]);
                }
            }
        }

        return ans;
    }
};

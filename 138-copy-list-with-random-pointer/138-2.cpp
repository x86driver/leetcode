/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        Node* copied = new Node(0);
        Node* node = copied;
        Node* h = head;
        while (h) {
            node->next = new Node(h->val);
            m[h] = node->next;
            h = h->next;
            node = node->next;
        }

        h = head;
        node = copied->next;
        while (h) {
            node->random = m[h->random];
            h = h->next;
            node = node->next;
        }
        return copied->next;
    }
};

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
        if (head == NULL) {
            return NULL;
        }
        Node* old_node = head;
        Node* new_node = new Node(old_node->val);
        Node* ret = new_node;
        unordered_map<Node*, Node*> m;

        while (old_node) {
            m[old_node] = new_node;
            old_node = old_node->next;
            if (old_node == NULL) {
                new_node->next = NULL;
            } else {
                new_node->next = new Node(old_node->val);
            }
            new_node = new_node->next;
        }

        old_node = head;
        new_node = ret;
        while (old_node) {
            new_node->random = m[old_node->random];
            new_node = new_node->next;
            old_node = old_node->next;
        }

        return ret;
    }
};

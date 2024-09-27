/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *node){
        vector<int> prev, post;
        Node *p = node->prev;
        while (p) {
            prev.push_back(p->val);
            p = p->prev;
        }
        while (node) {
            post.push_back(node->val);
            node = node->next;
        }
        post.insert(post.begin(), prev.rbegin(), prev.rend());
        return post;
    }
};

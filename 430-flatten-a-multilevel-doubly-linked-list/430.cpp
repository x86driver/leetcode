/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    //Node* prev;
    Node* dfs(Node* node) {
        if (!node) {
            return nullptr;;
        }
        Node* prev = nullptr;
        //cout << node->val << " ";
        if (node->child) {
            prev = node->next;
            node->next = node->child;
            node->child = nullptr;
        }
        
        if (node->next) {
            node->next->prev = node;
        }
        Node* ret = dfs(node->next);
        if (prev) {
            // cout << "prev: " << prev->val << " from " << node->val;
            // if (ret == nullptr) {
                // cout << " (ret: null" << endl;
            // } else {
            if (ret) {
                // cout << " (ret: " << ret->val << ")" << endl;
                ret->next = prev;
                prev->prev = ret;
                while (ret->next) {
                    // cout << ret->val << " ";
                    ret = ret->next;
                }
            }
            
        }
        if (node->next == nullptr) {
            return node;
        } else {
            return ret;
        }
    }
public:
    Node* flatten(Node* head) {
        dfs(head);
        // cout << endl << "正序: ";
        // Node* tmp = head;
        // Node* prev = head;
        // while (tmp) {
        //     cout << tmp->val << " ";
        //     prev = head;
        //     tmp = tmp->next;
        // }

        // cout << endl << "反向: ";
        // while (prev) {
        //     cout << prev->val << " ";
        //     prev = prev->prev;
        // }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater_head = new ListNode;
        ListNode *greater_node = greater_head;
        ListNode *less_head = new ListNode;
        ListNode *less_node = less_head;
        ListNode *node = head;

        while (node) {
            if (node->val < x) {
                less_node->next = new ListNode(node->val);
                less_node = less_node->next;
            } else {
                greater_node->next = new ListNode(node->val);
                greater_node = greater_node->next;
            }
            node = node->next;
        }

        less_node->next = greater_head->next;
        return less_head->next;
    }
};

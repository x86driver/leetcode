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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        int total = 0;
        ListNode* node = head;
        while (node) {
            ++total;
            node = node->next;
        }

        k %= total;
        ListNode* newhead = head;
        while (k--) {
            node = newhead;
            while (node) {
                if (node->next && node->next->next == nullptr) {
                    newhead = node->next;
                    node->next = nullptr;
                    newhead->next = head;
                    head = newhead;
                    break;
                }
                node = node->next;
            }
        }
        return newhead;
    }
};

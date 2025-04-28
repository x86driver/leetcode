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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* orig = head;
        ListNode* next = head->next;
        int last = head->val;

        while (head) {
            while (next && next->val == last) {
                next = next->next;
            }
            head->next = next;
            head = head->next;
            if (!next) {
                break;
            }
            next = next->next;
            last = head->val;
        }
        return orig;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ans = head;
        ListNode *prev = new ListNode(-1, head);
        if (prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            head = ans = second;
            prev = prev->next;
        }
        if (ans && ans->next)
            ans = ans->next;
        if (prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            ans->next = second;
            prev = prev->next;
        }

        prev = prev->next;
        while (prev && prev->next && prev->next->next) {
            if (ans && ans->next)
                ans = ans->next->next;
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            ans->next = second;
            prev = prev->next;
            if (prev)
                prev = prev->next;
        }

        return head;
    }
    ListNode* swapPairs2(ListNode* head) {
        ListNode *ans = head;
        ListNode *prev = new ListNode(-1, head);
        if (prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            head = ans = second;
            prev = prev->next;
        }
        if (ans && ans->next)
            ans = ans->next;
        if (prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            ans->next = second;
            prev = prev->next;
        }
        if (ans && ans->next)
            ans = ans->next->next;
        prev = prev->next;
        if (prev && prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            ans->next = second;
            prev = prev->next;
        }

        if (ans && ans->next)
            ans = ans->next->next;
        if (prev)
            prev = prev->next;
        if (prev && prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            first->next = second->next;
            second->next = first;
            ans->next = second;
            prev = prev->next;
        }
        return head;
    }
};

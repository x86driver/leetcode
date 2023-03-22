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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* node = head;

        div_t d = {.quot = 0, .rem = 0};
        while (l1 || l2 || d.quot) {
            int a = 0, b = 0;
            if (l1)
                a = l1->val;
            if (l2)
                b = l2->val;

            d = div(a + b + d.quot, 10);
            node->next = new ListNode(d.rem);
            node = node->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return head->next;
    }
};

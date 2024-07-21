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
        ListNode* ans = new ListNode;
        ListNode* node = ans;
        int carry = 0;
        while (l1 && l2) {
            node->next = new ListNode;
            node->next->val = l1->val + l2->val + carry;
            if (node->next->val >= 10) {
                carry = 1;
                node->next->val -= 10;
            } else {
                carry = 0;
            }
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            node->next = new ListNode;
            node->next->val = l1->val + carry;
            if (node->next->val >= 10) {
                carry = 1;
                node->next->val -= 10;
            } else {
                carry = 0;
            }
            node = node->next;
            l1 = l1->next;
        }

        while (l2) {
            node->next = new ListNode;
            node->next->val = l2->val + carry;
            if (node->next->val >= 10) {
                carry = 1;
                node->next->val -= 10;
            } else {
                carry = 0;
            }
            node = node->next;
            l2 = l2->next;
        }

        if (carry) {
            node->next = new ListNode;
            node->next->val = 1;
        }

        return ans->next;

    }
};

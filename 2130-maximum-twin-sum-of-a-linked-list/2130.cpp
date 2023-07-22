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
    int pairSum(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* fast = head;
        while (head && fast) {
            fast = fast->next->next;
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }

        int maximum = 0;
        while (curr) {
            maximum = max(maximum, curr->val + head->val);
            curr = curr->next;
            head = head->next;
        }
        return maximum;
    }
};

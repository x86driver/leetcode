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
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        int sum = 0;
        while (curr) {
            sum = max(sum, curr->val + head->val);
            curr = curr->next;
            head = head->next;
        }
        return sum;
    }
};

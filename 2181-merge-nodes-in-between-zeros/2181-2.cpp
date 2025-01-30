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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = head;
        while (head) {
            if (head->val == 0) {
                ListNode* nonZero = head->next;
                while (nonZero && nonZero->val != 0) {
                    head->val += nonZero->val;
                    nonZero = nonZero->next;
                }
                head->next = nonZero;
            }
            if (head->next->val == 0 && !head->next->next) {
                head->next = nullptr;
                break;
            }
            head = head->next;
        }
        return ans;
    }
};

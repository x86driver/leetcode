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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* ret = head;
        while (head && head->next) {
            int keep = m - 1;
            while (head && keep--) {
                head = head->next;
            }
            int del = n;
            while (head && head->next && del--) {
                head->next = head->next->next;
            }
            if (head)
                head = head->next;
        }

        return ret;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        int count = 0;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            ++count;
        }

        count = count * 2 + 1;
        if (fast)
            ++count;

        int target = count - n;
        int slow_count = (count + 1) / 2;

        if (target == 0)
            return head->next;
        if (target >= slow_count) {
            for (; slow_count < target; ++slow_count)
                slow = slow->next;
            slow->next = slow->next->next;
        } else {
            ListNode* node = head;
            for (int i = 0; i < target - 1; ++i)
                node = node->next;
            if (node->next)
                node->next = node->next->next;
            else
                return nullptr;
        }
        return head;
    }
};

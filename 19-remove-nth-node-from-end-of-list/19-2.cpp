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
        if (!head->next && n == 1)
            return nullptr;
        ListNode *fast = head->next;
        ListNode *slow = head;
        int curr = 0;
        int total = 0;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            ++curr;
        }
        total = curr * 2 + 1;
        if (fast) {
            cout << "has next" << endl;
            total += 1;
        }
        cout << slow->val << endl;
        cout << "Curr: " << curr << ", Total: " << total << endl;

        int distance = total - n - curr - 1;
        cout << "distance: " << distance << endl;
        if (distance < 0) {
            slow = head;
            distance = total - n - 1;
            cout << "New distance: " << distance << endl;
            if (distance == -1)
                return head->next;
        }
        for (int i = 0; i < distance; ++i) {
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

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
private:
    int gcd(int a, int b) {
        int ans = 1;
        for (int i = 2; i <= max(a, b); ++i) {
            if ((a % i) == 0 && (b % i) == 0)
                ans = i;
        }
        return ans;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *node = head;
        while (node && node->next) {
            int a = node->val;
            int b = node->next->val;
            ListNode *tmp = new ListNode(gcd(a, b), node->next);
            node->next = tmp;
            node = node->next->next;
        }

        return head;
    }
};

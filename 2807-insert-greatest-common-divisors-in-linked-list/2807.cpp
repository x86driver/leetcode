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
        int g = 1;
        int n = 2;
        while (n <= a && n <= b) {
            if (a % n == 0 && b % n == 0) {
                a /= n;
                b /= n;
                g *= n;
            } else {
                ++n;
            }
        }
        return g;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* newhead = new ListNode(0, head);
        while (head) {
            if (head->next) {
                ListNode* node = new ListNode(gcd(head->val, head->next->val), head->next);
                head->next = node;
                head = head->next;
            }
            head = head->next;
        }

        return newhead->next;
    }
};


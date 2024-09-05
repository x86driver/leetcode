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
    ListNode* frequenciesOfElements(ListNode* head) {
        map<int, int> m;
        while (head) {
            ++m[head->val];
            head = head->next;
        }
        ListNode *ans = new ListNode;
        ListNode *node = ans;
        for (const pair<int, int> &p: m) {
            node->next = new ListNode(p.second);
            node = node->next;
        }
        return ans->next;
    }
};

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
    ListNode* plusOne(ListNode* head) {
        vector<int> v;
        ListNode* orig_head = head;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int carry = 0;
        ++v[v.size() - 1];
        for (int i = v.size() - 1; i >= 0; --i) {
            v[i] += carry;
            if (v[i] >= 10) {
                v[i] %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        ListNode new_head;
        if (carry) {
            new_head.next = new ListNode(carry);
            new_head.next->next = orig_head;
        } else {
            new_head.next = orig_head;
        }

        head = orig_head;
        for (int i = 0; i < v.size(); ++i) {
            head->val = v[i];
            head = head->next;
        }

        return new_head.next;
    }
};

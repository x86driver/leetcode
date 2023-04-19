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
        ListNode* root = new ListNode;
        ListNode* node = root;
        int count = 0;
        head = head->next;
        while (head) {
            if (head->val == 0) {
                node->next = new ListNode(count);
                node = node->next;
                count = 0;
            } else {
                count += head->val;
            }
            head = head->next;
        }

        return root->next;
    }
};

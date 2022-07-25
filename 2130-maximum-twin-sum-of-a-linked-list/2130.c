/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define max(a,b) ((a) > (b) ? (a) : (b))

int pairSum(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast) {
        if (fast->next) {
            fast = fast->next->next;
        }
        slow = slow->next;
    }

    // reverse from slow
    struct ListNode* curr = slow;
    struct ListNode* prev = NULL;
    while (curr != NULL) {
        struct ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    int maximum = 0;
    while (prev) {
        maximum = max(maximum, head->val + prev->val);
        head = head->next;
        prev = prev->next;
    }

    return maximum;
}

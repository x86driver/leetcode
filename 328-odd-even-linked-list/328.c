/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* even_tmp = head->next;

    while (odd && even) {
        if (even->next == NULL) {
            break;
        }
        odd->next = even->next;
        odd = odd->next;
        if (odd->next == NULL) {
            even->next = NULL;
            break;
        }
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_tmp;

    return head;
}

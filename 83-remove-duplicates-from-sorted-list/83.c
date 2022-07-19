/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* ret = head;
    while (head != NULL) {
        if (head->next) {
            if (head->val == head->next->val) {
                struct ListNode* tmp = head->next;
                head->next = head->next->next;
                free(tmp);
                continue;
            }
        }
        head = head->next;
    }
    return ret;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* node = head;
    struct ListNode* prev = head;

    while (node != NULL) {
        if (node->val == val) {
            if (node->next) {
                node->val = node->next->val;
                struct ListNode* tmp = node->next;
                node->next = node->next->next;
                free(tmp);
                continue;
            } else { // tail
                free(node);
                if (prev == node) {
                    return NULL;
                }
                prev->next = NULL;
                break;
            }
        }

        prev = node;
        node = node->next;
    }

    return head;
}

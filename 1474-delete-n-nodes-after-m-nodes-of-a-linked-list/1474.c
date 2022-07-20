/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* freeNodes(struct ListNode* head, int count) {
    while (head && count >= 0) {
        struct ListNode* tmp = head;
        head = head->next;
        //free(tmp);
        --count;
    }
    return head;
}

struct ListNode* deleteNodes(struct ListNode* head, int m, int n){
    int count_m = 1;
    struct ListNode* node = head;

    while (node) {
        if (count_m == m && node) {
            node->next = freeNodes(node, n);
            count_m = 0;
        }
        ++count_m;
        node = node->next;
    }

    return head;
}

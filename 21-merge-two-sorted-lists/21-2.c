/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head;
    struct ListNode *node;

    if (list1 && !list2)
        return list1;
    if (!list1 && list2)
        return list2;
    if (!list1 && !list2)
        return NULL;

    if (list1->val <= list2->val) {
        head = node = list1;
        list1 = list1->next;
    } else {
        head = node = list2;
        list2 = list2->next;
    }

    while (list1) {
        if (!list2)
            break;
        if (list1->val <= list2->val) {
            node->next = list1;
            list1 = list1->next;
        } else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }

    if (list1)
        node->next = list1;
    if (list2)
        node->next = list2;

    return head;
}

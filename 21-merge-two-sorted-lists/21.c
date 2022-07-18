/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* node = NULL;
    struct ListNode* ret = NULL;

    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    if (list1->val < list2->val) {
        node = ret = list1;
        list1 = list1->next;
    } else {
        node = ret = list2;
        list2 = list2->next;
    }

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            node->next = list1;
            node = node->next;
            list1 = list1->next;
        } else {
            node->next = list2;
            node = node->next;
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        node->next = list1;
        node = node->next;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        node->next = list2;
        node = node->next;
        list2 = list2->next;
    }
    return ret;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *fast = head->next;
    struct ListNode *slow = head;

    if (fast->next == slow)
        return slow;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast)
            break;
        fast = fast->next->next;
        slow = slow->next;
    }

    if (slow == NULL || fast == NULL || fast->next == NULL)
        return NULL;

    slow = head;
    while (true) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next == slow)
            return slow;
    }

    return NULL;
}

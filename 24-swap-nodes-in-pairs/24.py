# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        third = head.next.next
        tmp = head.next
        prev_head = head
        head.next = third
        tmp.next = head
        ret_head = tmp

        while tmp.next.next:
            head = tmp.next.next
            if not head.next:
                break
            third = head.next.next
            tmp = head.next
            head.next = third
            tmp.next = head
            prev_head.next = tmp
            prev_head = head

        return ret_head

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = head
        prev = head

        while fast != None and fast.next != None:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        curr = prev.next
        prev.next = None
        prev = None
        while curr != None:
            n = curr.next
            curr.next = prev
            prev = curr
            curr = n

        mid = prev
        new_head = head

        while mid != None:
            first_next = new_head.next
            second_next = mid.next
            new_head.next = mid
            if first_next is None and second_next is not None:
                break
            mid.next = first_next
            new_head = first_next
            mid = second_next

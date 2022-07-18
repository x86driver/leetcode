# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res = 0
        while True:
            res |= head.val
            head = head.next
            if head == None:
                break
            res <<= 1

        return res

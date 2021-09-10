class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        tables = {}
        while head != None:
            if head in tables:
                return True
            tables[head] = 1
            head = head.next

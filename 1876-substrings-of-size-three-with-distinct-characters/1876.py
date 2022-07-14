class Solution:
    def isUniq(self, s):
        return len(s) == 3 and s[0] != s[1] != s[2] and s[0] != s[2]

    def countGoodSubstrings(self, s: str) -> int:
        head = 0
        tail = head + 3
        num = 0

        while tail <= len(s):
            if self.isUniq(s[head:tail]):
                num += 1
            head += 1
            tail += 1

        return num

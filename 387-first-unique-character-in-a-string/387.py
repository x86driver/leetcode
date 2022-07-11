class Solution:
    def firstUniqChar(self, s: str) -> int:
        table = Counter(s)

        for i,v in enumerate(s):
            if table[v] == 1:
                return i

        return -1

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        table = Counter(s)

        for c in t:
            if c in table:
                if table[c] == 1:
                    del table[c]
                else:
                    table[c] -= 1
            else:
                return c

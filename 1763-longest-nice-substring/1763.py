class Solution:
    def isNice(self, s: str):
        table = set(s)
        for c in s:
            if c.swapcase() not in table:
                return False
        return True

    def longestNiceSubstring(self, s: str) -> str:
        ptr1 = 0
        ptr2 = 0
        length = 0
        ans = ""

        while ptr1 < len(s) - 1:
            ptr2 = ptr1 + 1
            while ptr2 < len(s):
                sub = s[ptr1:ptr2+1]
                if self.isNice(sub):
                    if len(sub) > length:
                        length = len(sub)
                        ans = sub
                ptr2 += 1
            ptr1 += 1

        return ans

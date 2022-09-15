class Solution:
    def balancedStringSplit(self, s: str) -> int:
        n = 0
        ans = 0
        for i in range(len(s)):
            if s[i] == 'L':
                n += 1
            else:
                n -= 1
            if n == 0:
                ans += 1

        return ans

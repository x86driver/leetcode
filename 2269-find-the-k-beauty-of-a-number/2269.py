class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        ptr1 = 0
        ptr2 = k - 1
        count = 0

        while ptr1 < len(s) - k + 1 and ptr2 < len(s):
            sub = int(s[ptr1:ptr2+1])
            if sub != 0 and (num % sub) == 0:
                count += 1
            ptr1 += 1
            ptr2 += 1

        return count

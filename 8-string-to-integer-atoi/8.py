class Solution:
    def myAtoi(self, s: str) -> int:
        ret = 0
        numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        neg = False
        start = 0
        while start < len(s):
            if s[start] == ' ':
                start += 1
            else:
                break

        if start == len(s):
            return 0
        if s[start] not in numbers and s[start] != '-' and s[start] != '+':
            return 0

        changed = False
        num_start = False

        for i in range(start, len(s)):
            if s[i] == '-':
                if changed or num_start:
                    break
                else:
                    changed = True
                neg = True
                continue
            elif s[i] == '+':
                if changed or num_start:
                    break
                else:
                    changed = True
                neg = False
                continue
            elif s[i] not in numbers:
                break
            num_start = True
            ret *= 10
            ret += int(s[i])

        if neg:
            if ret >= 2147483648:
                return -2147483648
            else:
                return -ret
        else:
            if ret >= 2147483647:
                return 2147483647
            else:
                return ret

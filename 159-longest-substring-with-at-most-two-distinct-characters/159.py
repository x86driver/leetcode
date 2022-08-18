class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        if len(s) <= 2:
            return len(s)

        ans = 0
        head = 0
        tail = 1
        length = 2
        table = {s[0]: 1}

        while tail < len(s):
            if s[tail] in table:
                table[s[tail]] += 1
                tail += 1
                continue

            elif len(table) == 1:
                table[s[tail]] = 1
                tail += 1
                continue

            else:
                ans = max(ans, tail-head)
                while head < tail:
                    table[s[head]] -= 1
                    if table[s[head]] == 0:
                        table.pop(s[head], None)
                    head += 1
                    if len(table) == 1:
                        break

        ans = max(ans, tail-head)
        return ans

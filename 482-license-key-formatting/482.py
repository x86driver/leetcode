class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        ans = []
        i = len(s) - 1
        counter = 0

        while i >= 0:
            if s[i] == '-':
                i -= 1
                continue

            ans.append(s[i].upper())
            if counter == k-1:
                ans.append('-')
                counter = 0
            else:
                counter += 1
            i -= 1

        ans.reverse()
        if ans and ans[0] == '-':
            del ans[0]
        return ''.join(ans)

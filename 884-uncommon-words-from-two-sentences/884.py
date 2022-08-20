class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ans = []
        table = {}

        for s in (s1 + " " + s2).split():
            if s in table:
                table[s] += 1
            else:
                table[s] = 1

        for t in table:
            if table[t] == 1:
                ans.append(t)

        return ans

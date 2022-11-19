class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        table = {}
        ans = []

        for i in range(len(s)):
            if len(s) - i < 10:
                break
            sub = s[i:i+10]
            if sub in table:
                table[sub] += 1
            else:
                table[sub] = 1

        for dna in table:
            if table[dna] > 1:
                ans.append(dna)

        return ans

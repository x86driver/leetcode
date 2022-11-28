class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        table = Counter(words)
        ans = []
        reverse_table = {}

        for t in table:
            if table[t] in reverse_table:
                reverse_table[table[t]].append(t)
            else:
                reverse_table[table[t]] = [t]

        s = sorted(reverse_table.items(), reverse=True)

        i = 0
        while k > 0:
            groups = s[i][1]
            groups.sort()
            j = 0
            while k > 0 and j < len(groups):
                ans.append(groups[j])
                k -= 1
                j += 1
            i += 1

        return ans

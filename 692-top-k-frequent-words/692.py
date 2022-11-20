class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        table = Counter(words)
        ans = []

        reverse_table = {}
        for word in table:
            if table[word] in reverse_table:
                reverse_table[table[word]].append(word)
            else:
                reverse_table[table[word]] = [word]

        for s in sorted(reverse_table, reverse=True):
            lists = reverse_table[s]
            lists.sort()
            i = 0
            while i < len(lists) and k > 0:
                ans.append(lists[i])
                i += 1
                k -= 1
            if k == 0:
                break

        return ans

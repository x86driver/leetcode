class Solution:
    def frequencySort(self, s: str) -> str:
        table = Counter(s)
        ans = ""
        for pair in table.most_common():
            for i in range(pair[1]):
                ans += pair[0]

        return ans

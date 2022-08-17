class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        ans = []
        counter = Counter(nums)
        table = {}
        for c in counter:
            if counter[c] in table:
                table[counter[c]].append(c)
            else:
                table[counter[c]] = [c]

        for k,v in sorted(table.items(), key=lambda x:x[0]):
            for j in sorted(v, reverse=True):
                for i in range(k):
                    ans.append(j)

        return ans

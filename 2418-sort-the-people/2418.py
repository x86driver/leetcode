class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        table = {}
        ans = []

        for i in range(len(heights)):
            table[heights[i]] = i

        for height,index in sorted(table.items(), reverse=True):
            ans.append(names[index])

        return ans

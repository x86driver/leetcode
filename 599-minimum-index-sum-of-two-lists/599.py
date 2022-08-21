class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        table = {}
        ans = []
        minimum = math.inf

        for i in range(len(list1)):
            table[list1[i]] = i

        for i in range(len(list2)):
            if list2[i] in table:
                if table[list2[i]] + i == minimum:
                    minimum = table[list2[i]] + i
                    ans.append(list2[i])
                elif table[list2[i]] + i < minimum:
                    minimum = table[list2[i]] + i
                    ans = [list2[i]]

        return ans

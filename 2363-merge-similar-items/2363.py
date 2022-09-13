class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        ans = []
        i1 = sorted(items1)
        i2 = sorted(items2)

        ptr1 = 0
        ptr2 = 0

        while ptr1 < len(i1) and ptr2 < len(i2):
            if i1[ptr1][0] == i2[ptr2][0]:
                ans.append([i1[ptr1][0], i1[ptr1][1]+i2[ptr2][1]])
                ptr1 += 1
                ptr2 += 1
            elif i1[ptr1][0] < i2[ptr2][0]:
                ans.append([i1[ptr1][0], i1[ptr1][1]])
                ptr1 += 1
            else:
                ans.append([i2[ptr2][0], i2[ptr2][1]])
                ptr2 += 1

        while ptr1 < len(i1):
            ans.append(i1[ptr1])
            ptr1 += 1

        while ptr2 < len(i2):
            ans.append(i2[ptr2])
            ptr2 += 1

        return ans

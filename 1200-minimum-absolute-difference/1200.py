class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        ans = []
        arr.sort()

        diff = arr[1] - arr[0]
        minIndex = 0
        for i in range(1, len(arr)-1):
            if arr[i+1] - arr[i] < diff:
                diff = arr[i+1] - arr[i]
                minIndex = i

        for i in range(minIndex, len(arr)-1):
            for j in range(i+1, len(arr)):
                if arr[j] - arr[i] == diff:
                    ans.append([arr[i], arr[j]])
                    break
                if arr[j] - arr[i] > diff:
                    break

        return ans

class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()

        deleteCount = int(len(arr) * 0.05)

        return sum(arr[deleteCount:len(arr)-deleteCount]) / (len(arr) - 2 * deleteCount)

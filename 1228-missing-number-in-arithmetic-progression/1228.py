class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        diffs = {}
        mode = 0
        count = 0

        for i in range(1, len(arr)):
            diff = arr[i] - arr[i-1]
            if diff in diffs:
                diffs[diff] += 1
            else:
                diffs[diff] = 1
            if diffs[diff] > count:
                count = diffs[diff]
                mode = diff

        ans = arr[0]
        for i in range(1, len(arr)):
            if arr[i] - arr[i-1] != mode:
                ans = arr[i] - mode
                break

        return ans

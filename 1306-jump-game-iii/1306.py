class Solution:
    def dfs(self, arr, valid, n):
        if n < 0 or n >= len(arr):
            return False

        if valid[n] == True:
            return False

        if arr[n] == 0:
            return True

        valid[n] = True

        return self.dfs(arr, valid, n - arr[n]) or self.dfs(arr, valid, n + arr[n])

    def canReach(self, arr: List[int], start: int) -> bool:
        valid = [False] * len(arr)
        return self.dfs(arr, valid, start)

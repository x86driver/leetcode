class Solution:
    def bsearch(self, arr, target):
        head = 0
        tail = len(arr) - 1

        while head <= tail:
            mid = head + (tail - head) // 2
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                head = mid + 1
            else:
                tail = mid - 1

        return False

    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        ans = []
        for a in arr1:
           if self.bsearch(arr2, a) and self.bsearch(arr3, a):
               ans.append(a)

        return ans

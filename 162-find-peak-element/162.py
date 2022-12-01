class Solution:
    def bsearch(self, num):
        head = 0
        tail = len(num) - 1

        while head < tail:
            mid = head + (tail - head) // 2
            if num[mid-1] < num[mid] > num[mid+1]:
                return mid
            if num[mid-1] < num[mid] < num[mid+1]:
                head = mid + 1
            elif num[mid-1] > num[mid] > num[mid+1]:
                tail = mid - 1
            else:
                head = mid + 1

        return head

    def findPeakElement(self, nums: List[int]) -> int:
        return self.bsearch(nums)

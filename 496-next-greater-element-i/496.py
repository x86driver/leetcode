class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        for num in nums1:
            i = 0
            greater = None
            while i < len(nums2):
                if nums2[i] == num:
                    i += 1
                    break
                i += 1

            while i < len(nums2):
                if nums2[i] > num:
                    greater = nums2[i]
                    break
                i += 1

            if greater:
                ans.append(greater)
            else:
                ans.append(-1)

        return ans

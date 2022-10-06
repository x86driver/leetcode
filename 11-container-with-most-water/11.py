class Solution:
    def maxArea(self, height: List[int]) -> int:
        head = 0
        tail = len(height) - 1
        area = 0

        while head < tail:
            area = max(area, min(height[head], height[tail]) * (tail - head))
            if height[head] < height[tail]:
                head += 1
            else:
                tail -= 1

        return area

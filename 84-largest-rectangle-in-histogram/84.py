class Rect:
    height = 0
    width = 0
    def __init__(self, height, width):
        self.height = height
        self.width = width

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        s = []
        ans = 0
        heights.append(0)

        for h in heights:
            accumulated_width = 0
            while s and s[-1].height >= h:
                accumulated_width += s[-1].width
                ans = max(ans, accumulated_width * s[-1].height)
                s.pop()

            s.append(Rect(height=h, width=accumulated_width + 1))

        return ans

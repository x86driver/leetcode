class Solution:
    def slope(self, p1, p2):
        return (p2[1]-p1[1]) / (p2[0]-p1[0])
    def isBoomerang(self, points: List[List[int]]) -> bool:
        if points[0] == points[1] or points[1] == points[2]:
            return False
        if points[0][0] == points[1][0]:
            return points[1][0] != points[2][0]
        if points[1][0] == points[2][0]:
            return points[1][1] != points[2][1]
        slope1 = self.slope(points[0], points[1])
        slope2 = self.slope(points[1], points[2])

        return slope1 != slope2

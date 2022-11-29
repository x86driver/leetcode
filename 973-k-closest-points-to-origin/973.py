class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distance = []
        ans = []

        for i in range(len(points)):
            x,y = points[i]
            d = x*x+y*y
            distance.append([d, i])

        distance = sorted(distance)

        for i in range(k):
            ans.append(points[distance[i][1]])

        return ans

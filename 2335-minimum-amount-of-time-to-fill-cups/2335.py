class Solution:
    def fillCups(self, amount: List[int]) -> int:
        count = 0
        h = []
        for a in amount:
            if a != 0:
                heappush(h, -a)

        while len(h) > 1:
            x = heappop(h)
            y = heappop(h)
            x += 1
            y += 1
            if x < 0:
                heappush(h, x)
            if y < 0:
                heappush(h, y)

            count += 1

        return count - sum(h)

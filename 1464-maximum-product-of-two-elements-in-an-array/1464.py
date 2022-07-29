class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        neg = list(map(lambda x: -x, nums))
        heapify(neg)

        a = heappop(neg)
        b = heappop(neg)

        return (a+1)*(b+1)

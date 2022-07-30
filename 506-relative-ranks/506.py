class Solution:
    def toStr(self, rank: int, length: int) -> str:
        ranks = ["", "Gold Medal", "Silver Medal", "Bronze Medal"]
        if rank < len(ranks):
            return ranks[rank]
        return str(rank)

    def findRelativeRanks(self, score: List[int]) -> List[str]:
        positions = []
        ans = [None] * len(score)
        for i,v in enumerate(score):
            positions.append([i,v])

        positions.sort(key=lambda x: x[1], reverse=True)

        rank = 1
        for idx,_ in positions:
            ans[idx] = self.toStr(rank, len(score))
            rank += 1

        return ans

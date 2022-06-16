class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row = []
        col = []
        
        for r in matrix:
            row.append(min(r))
        
        for j in range(len(matrix[0])):
            maximum = matrix[0][j]
            for i in range(len(matrix)):
                maximum = max(matrix[i][j], maximum)
            col.append(maximum)
        
        ans = []
        for r in row:
            if r in col:
                ans.append(r)
        
        return ans

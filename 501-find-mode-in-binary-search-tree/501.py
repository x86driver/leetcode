class Solution:
    def dfs(self, root):
        if root is None:
            return

        if root.val not in self.table:
            self.table[root.val] = 1
        else:
            self.table[root.val] += 1

        self.dfs(root.left)
        self.dfs(root.right)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.table = {}
        self.dfs(root)
        sort = sorted(self.table.items(), key=lambda x:x[1], reverse=True)

        ans = []
        Max = -math.inf
        for k,v in sort:
            if v >= Max:
                ans.append(k)
                Max = v

        return ans

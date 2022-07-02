class Solution:
    def dfs(self, root, level):
        if root is None:
            return

        self.tree.append([root.val, level])
        self.maxLevel = max(self.maxLevel, level)

        self.dfs(root.left, level+1)
        self.dfs(root.right, level+1)
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        self.maxLevel = -math.inf
        self.tree = []
        self.dfs(root, 0)

        result = [[] for _ in range(self.maxLevel + 1)]

        for val,level in self.tree:
            result[level].append(val)

        ans = []
        for v in result:
            ans.append(sum(v) / len(v))

        return ans

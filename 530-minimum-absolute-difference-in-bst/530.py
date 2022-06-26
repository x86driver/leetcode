class Solution:
    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)
        if self.prev is not None:
            self.curr_min = min(self.curr_min, root.val - self.prev)
        self.prev = root.val
        self.dfs(root.right)

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.curr_min = math.inf
        self.prev = None
        self.dfs(root)

        return self.curr_min

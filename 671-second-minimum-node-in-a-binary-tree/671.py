class Solution:
    def dfs(self, root):
        if root is None:
            return

        if root.val < self.small[0] and root.val != self.small[1]:
            self.small[0] = root.val
        elif root.val < self.small[1] and root.val != self.small[0]:
            self.small[1] = root.val

        self.dfs(root.left)
        self.dfs(root.right)
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        self.small = [math.inf, math.inf]
        self.dfs(root)

        if self.small[1] == math.inf:
            return -1
        return self.small[1]

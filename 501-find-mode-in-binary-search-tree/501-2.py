class Solution:
    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)
        if root.val == self.prev:
            self.counter += 1
        else:
            self.counter = 1
        if self.counter == self.max_count:
            self.result.append(root.val)
        elif self.counter > self.max_count: # reset self.result
            self.result = [root.val]
            self.max_count = self.counter
        self.prev = root.val
        self.dfs(root.right)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.prev = None
        self.counter = 0
        self.max_count = 0
        self.result = []
        self.dfs(root)

        return self.result

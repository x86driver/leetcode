class Solution:
    def dfs(self, root):
        if root is None:
            return
        self.dfs(root.left)
        self.dfs(root.right)

        if root.left is None and root.right is None:
            self.result.append(root.val)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.result = []
        self.dfs(root1)
        res1 = self.result.copy()
        self.result = []
        self.dfs(root2)

        return res1 == self.result

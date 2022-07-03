class Solution:
    def dfs(self, root):
        if root is None:
            return

        self.ans.append(root.val)
        self.dfs(root.left)
        self.dfs(root.right)

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)

        return self.ans

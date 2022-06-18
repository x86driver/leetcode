class Solution:
    def dfs(self, root, isleft):
        if root is None:
            return
        
        self.dfs(root.left, True)
        self.dfs(root.right, False)
        
        if root.left is None and root.right is None and isleft:
            self.sum += root.val
        
        return 
        
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.sum = 0
        self.dfs(root, False)
        return self.sum

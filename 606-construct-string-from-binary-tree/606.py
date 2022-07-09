# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        if root is None:
            return
        self.arr.append(root.val)

        if not root.left and not root.right:
            return

        self.arr.append('(')
        self.dfs(root.left)
        self.arr.append(')')

        if not root.right:
            return
        self.arr.append('(')
        self.dfs(root.right)
        self.arr.append(')')

    def tree2str(self, root: Optional[TreeNode]) -> str:
        self.arr = []
        self.dfs(root)

        return ''.join(str(x) for x in self.arr)

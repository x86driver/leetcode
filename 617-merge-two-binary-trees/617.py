# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root1, root2, parent, isLeft):
        if root1 is None and root2 is None:
            return

        if root1 is None:
            root1 = TreeNode(val=0)
            if isLeft:
                parent.left = root1
            else:
                parent.right = root1

        if root2:
            root1.val += root2.val

        if root2:
            self.dfs(root1.left, root2.left, root1, True)
            self.dfs(root1.right, root2.right, root1, False)
        else:
            self.dfs(root1.left, None, root1, True)
            self.dfs(root1.right, None, root1, False)

    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if root1 is None:
            return root2
        elif root2 is None:
            return root1
        self.dfs(root1, root2, root1, False)
        return root1

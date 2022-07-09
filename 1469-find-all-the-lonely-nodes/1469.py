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

        self.dfs(root.left)
        self.dfs(root.right)

        if root.left and not root.right:
            self.ans.append(root.left.val)
        elif root.right and not root.left:
            self.ans.append(root.right.val)

    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans

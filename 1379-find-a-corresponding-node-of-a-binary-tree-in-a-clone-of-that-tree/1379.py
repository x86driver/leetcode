# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root:TreeNode, target: TreeNode) -> TreeNode:
        if root is None:
            return None

        if root.val == target.val:
            return root

        return self.dfs(root.left, target) or self.dfs(root.right, target)

    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        return self.dfs(cloned, target)

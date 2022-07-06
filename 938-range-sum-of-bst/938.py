# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find(self, root, low, high):
        if root is None:
            return

        if low <= root.val <= high:
            self.sum += root.val

        if root.val > low:
            self.find(root.left, low, high)

        if root.val < high:
            self.find(root.right, low, high)

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.sum = 0
        self.find(root, low, high)
        return self.sum

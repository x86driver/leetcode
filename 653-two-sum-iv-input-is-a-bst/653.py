# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, node):
        if node is None:
            return False

        self.traverse(node.left)
        self.traverse(node.right)

        self.arr.append(node.val)

    def find(self, root, n, target):
        if root is None:
            return False

        if root.val == target and root.val != n:
            return True

        if root.val > target:
            return self.find(root.left, n, target)
        else:
            return self.find(root.right, n, target)

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.arr = []

        self.traverse(root)

        for n in self.arr:
            if self.find(root, n, k-n):
                return True

        return False

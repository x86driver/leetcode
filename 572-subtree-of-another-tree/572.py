# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find(self, root, val):
        if root is None:
            return
        if root.val == val:
            self.nodes.append(root)
        self.find(root.left, val)
        self.find(root.right, val)

    def isIdentical(self, r1, r2):
        if r1 is None and r2 is None:
            return True
        if r1 is None and r2:
            return False
        if r1 and r2 is None:
            return False
        if r1.val != r2.val:
            return False
        return self.isIdentical(r1.left, r2.left) and self.isIdentical(r1.right, r2.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        self.nodes = []
        self.find(root, subRoot.val)
        for n in self.nodes:
            if self.isIdentical(n, subRoot):
                return True
        return False

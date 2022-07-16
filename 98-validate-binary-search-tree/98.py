# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Info:
    def __init__(self, isValid=True, minVal=math.inf, maxVal=-math.inf):
        self.isValid = isValid
        self.minVal = minVal
        self.maxVal = maxVal

class Solution:
    def dfs(self, root):
        if root is None:
            return Info()

        left = self.dfs(root.left)
        right = self.dfs(root.right)

        info = Info()
        info.isValid = left.isValid and right.isValid and left.maxVal < root.val and right.minVal > root.val
        info.minVal = min(root.val, left.minVal)
        info.maxVal = max(root.val, right.maxVal)
        return info

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        ret = self.dfs(root)

        return ret.isValid

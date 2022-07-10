# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, target):
        if root is None:
            return

        self.sum += root.val
        self.sets.append(root.val)

        self.dfs(root.left, target)
        self.dfs(root.right, target)

        if self.sum == target:
            if not root.left and not root.right:
                self.ans.append(self.sets.copy())
        self.sum -= root.val
        self.sets.pop()

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.sum = 0
        self.ans = []
        self.sets = []
        self.dfs(root, targetSum)

        return self.ans

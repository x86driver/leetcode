class Solution:
    def find(self, root, target):
        if root is None:
            return
        
        if abs(target - root.val) < self.diff:
            self.diff = abs(target - root.val)
            self.ans = root.val

        if target < root.val:
            self.find(root.left, target)
        else:
            self.find(root.right, target)
        
        
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        self.ans = root.val
        self.diff = math.inf
        self.find(root, target)
     
        return self.ans

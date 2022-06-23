class Solution:
    def find(self, root, p, q):
        if root is None:
            return

        self.parent = root

        if p.val > root.val and q.val > root.val:
            self.find(root.right, p, q)
        elif p.val < root.val and q.val < root.val:
            self.find(root.left, p, q)
        else:
            return
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.find(root, p, q)
        return self.parent

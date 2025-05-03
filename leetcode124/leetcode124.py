# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        self.max_val = float("-inf")
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            self.max_val = max(self.max_val, root.val + left + right)
            outSum = root.val + max(0, max(left, right))
  
            return max(outSum, 0)
        dfs(root)
        return self.max_val
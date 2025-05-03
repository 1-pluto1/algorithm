# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
               def dfs(node, presum):
                     if not node: return 0
                     presum += node.val

                     path_cnt = presum_counts.get(presum - targetSum, 0)
                     presum_counts[presum] = presum_counts.get(presum, 0) + 1
                     path_cnt += dfs(node.left, presum) + dfs(node.right, presum)
                     presum_counts[presum] -= 1     
                     
                     return path_cnt
               
               presum_counts = {0 : 1}
               return dfs(root, 0)
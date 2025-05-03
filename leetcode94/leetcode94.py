# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# 迭代法
# class Solution:
#     def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
#         res = []
#         node = root
#         st = []
#         while st or node:
#             if node:
#                 st.append(node)
#                 node = node.left
#             else:
#                 node = st.pop(-1)
#                 res.append(node.val)
#                 node = node.right
#         return res

# 递归法
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
       res = []
       self.dfs(root, res)
       return res
    
    def dfs(self, node, res):
        if not node: return res
        self.dfs(node.left, res)
        res.append(node.val)
        self.dfs(node.right, res)
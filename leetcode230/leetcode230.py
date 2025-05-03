class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        candidate_list = []
        
        def __traverse(root: TreeNode) -> None: 
            nonlocal candidate_list
            if not root: 
                return 
            __traverse(root.left)
            candidate_list.append(root.val)
            __traverse(root.right)
        
        __traverse(root)
        
        return candidate_list[k - 1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def dfs2(root, root2):
    if(not root and not root2):
        return True
    if(root and root2 and root.val==root2.val):
        return dfs2(root.left, root2.right) and dfs2(root.right, root2.left)
    return False
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return dfs2(root.left,root.right)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def trav(curr, prev, prevsum, target, res):
    prev.append(curr.val)
    prevsum += curr.val
    if not curr.left and not curr.right:
        if prevsum == target:
            res.append(prev.copy())
        prev.pop()
        return
    if curr.left:
        trav(curr.left, prev, prevsum, target, res)
    if curr.right:
        trav(curr.right, prev, prevsum, target, res)
    prev.pop()

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        if root:
            trav(root, [], 0, targetSum, res)
        return res
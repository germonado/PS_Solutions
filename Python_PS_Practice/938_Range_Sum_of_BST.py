# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    val = 0
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root is None:
            return 0
        if root:
            if root.val >= low and root.val <= high:
                self.val += root.val
                self.rangeSumBST(root.right, low, high)
                self.rangeSumBST(root.left, low,high)
            elif root.val < low:
                self.rangeSumBST(root.right, low, high)
            elif root.val > high:
                self.rangeSumBST(root.left, low,high)
        return self.val
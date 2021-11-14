# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if root1 is None:
            return root2
        elif root2 is None:
            return root1
        def dfs(node1, node2):
            if node1.left and node2.left:
                dfs(node1.left, node2.left)
            if node1.right and node2.right:
                dfs(node1.right, node2.right)
            if node1.left is None and node2.left:
                node1.left = node2.left
            if node1.right is None and node2.right:
                node1.right = node2.right
            node1.val += node2.val
        dfs(root1, root2)
        return root1
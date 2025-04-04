# Solution for Lowest Common Ancestor of Deepest Leaves in PY

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def solve(node):
            if not node:
                return (0, None)
            l_d, l_n = solve(node.left)
            r_d, r_n = solve(node.right)
            if l_d == r_d:
                return (l_d + 1, node)
            elif l_d > r_d:
                return (l_d + 1, l_n)
            else:
                return (r_d + 1, r_n)
        return solve(root)[1]

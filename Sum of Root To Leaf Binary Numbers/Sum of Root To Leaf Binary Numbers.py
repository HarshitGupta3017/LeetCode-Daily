# Solution for Sum of Root To Leaf Binary Numbers in PY

class Solution:
    def sumRootToLeaf(self, root) -> int:

        def solve(node, current_value):
            if not node:
                return 0

            # Shift left and add current bit
            current_value = (current_value << 1) + node.val

            # If leaf node
            if not node.left and not node.right:
                return current_value

            return solve(node.left, current_value) + solve(node.right, current_value)

        return solve(root, 0)

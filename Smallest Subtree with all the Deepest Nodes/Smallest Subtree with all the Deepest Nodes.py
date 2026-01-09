# Solution for Smallest Subtree with all the Deepest Nodes in PY

class Solution:
    def dfs(self, node):

        # Base case: empty subtree
        if not node:
            return 0, None

        # Recurse on left and right subtrees
        leftDepth, leftNode = self.dfs(node.left)
        rightDepth, rightNode = self.dfs(node.right)

        # If depths are equal, current node is the answer
        if leftDepth == rightDepth:
            return leftDepth + 1, node

        # If left subtree is deeper
        if leftDepth > rightDepth:
            return leftDepth + 1, leftNode

        # Right subtree is deeper
        return rightDepth + 1, rightNode

    def subtreeWithAllDeepest(self, root):
        return self.dfs(root)[1]

# Solution for Maximum Product of Splitted Binary Tree in PY

class Solution:
    MOD = 10**9 + 7

    def __init__(self):
        self.totalTreeSum = 0
        self.maxProductValue = 0

    # DFS to compute subtree sums and evaluate product when cutting an edge
    def computeSubtreeSum(self, currentNode):

        # Base case
        if not currentNode:
            return 0

        # Recursively compute left and right subtree sums
        leftSubtreeSum = self.computeSubtreeSum(currentNode.left)
        rightSubtreeSum = self.computeSubtreeSum(currentNode.right)

        # Sum of current subtree
        currentSubtreeSum = (
            currentNode.val + leftSubtreeSum + rightSubtreeSum
        )

        # Remaining tree sum if we cut above this subtree
        remainingSum = self.totalTreeSum - currentSubtreeSum

        # Update maximum product
        self.maxProductValue = max(
            self.maxProductValue,
            currentSubtreeSum * remainingSum
        )

        return currentSubtreeSum

    def maxProduct(self, root) -> int:
        if not root:
            return 0

        # First DFS: compute total sum of the tree
        self.totalTreeSum = self.computeSubtreeSum(root)

        # Second DFS: compute max product
        self.computeSubtreeSum(root)

        # Return modulo after maximizing
        return self.maxProductValue % self.MOD

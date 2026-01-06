# Solution for Maximum Level Sum of a Binary Tree in PY

class Solution:

    # DFS helper to accumulate sum of nodes at each level
    def calculateLevelSums(self, currentNode, currentLevel, levelSumMap):

        # Base case: empty node
        if not currentNode:
            return

        # Add current node's value to its level sum
        levelSumMap[currentLevel] = levelSumMap.get(currentLevel, 0) + currentNode.val

        # Recur for left and right subtrees
        self.calculateLevelSums(currentNode.left, currentLevel + 1, levelSumMap)
        self.calculateLevelSums(currentNode.right, currentLevel + 1, levelSumMap)

    def maxLevelSum(self, root) -> int:

        # Dictionary: level -> sum at that level
        levelSumMap = {}

        # Populate level sums using DFS
        self.calculateLevelSums(root, 1, levelSumMap)

        # Smallest level with maximum sum
        bestLevel = 1

        # Iterate through all levels
        for level, levelSum in levelSumMap.items():
            if (levelSum > levelSumMap[bestLevel] or
                (levelSum == levelSumMap[bestLevel] and level < bestLevel)):
                bestLevel = level

        return bestLevel

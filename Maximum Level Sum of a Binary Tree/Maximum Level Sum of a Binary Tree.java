// Solution for Maximum Level Sum of a Binary Tree in JAVA

class Solution {

    // DFS helper to accumulate sum of nodes at each level
    private void calculateLevelSums(
            TreeNode currentNode,
            int currentLevel,
            Map<Integer, Integer> levelSumMap
    ) {
        // Base case: empty node
        if (currentNode == null) return;

        // Add current node's value to its level sum
        levelSumMap.put(
                currentLevel,
                levelSumMap.getOrDefault(currentLevel, 0) + currentNode.val
        );

        // Recur for left and right subtrees
        calculateLevelSums(currentNode.left, currentLevel + 1, levelSumMap);
        calculateLevelSums(currentNode.right, currentLevel + 1, levelSumMap);
    }

    public int maxLevelSum(TreeNode root) {

        // Map: level -> sum of node values at that level
        Map<Integer, Integer> levelSumMap = new HashMap<>();

        // Populate level sums using DFS
        calculateLevelSums(root, 1, levelSumMap);

        // Smallest level with maximum sum
        int bestLevel = 1;

        // Iterate through all levels
        for (Map.Entry<Integer, Integer> entry : levelSumMap.entrySet()) {
            int level = entry.getKey();
            int levelSum = entry.getValue();

            // Update if sum is larger or same sum but smaller level
            if (levelSum > levelSumMap.get(bestLevel) ||
               (levelSum == levelSumMap.get(bestLevel) && level < bestLevel)) {
                bestLevel = level;
            }
        }

        return bestLevel;
    }
}

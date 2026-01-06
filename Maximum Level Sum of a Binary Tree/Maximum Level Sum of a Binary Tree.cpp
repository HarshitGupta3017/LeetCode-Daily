// Solution for Maximum Level Sum of a Binary Tree in CPP

class Solution {
public:

    // DFS helper to accumulate sum of nodes at each level
    void calculateLevelSums(
        TreeNode* currentNode,
        int currentLevel,
        unordered_map<int, int>& levelSumMap
    ) {
        // Base case: empty node
        if (currentNode == nullptr) return;

        // Add current node's value to its level sum
        levelSumMap[currentLevel] += currentNode->val;

        // Recur for left and right subtrees
        calculateLevelSums(currentNode->left, currentLevel + 1, levelSumMap);
        calculateLevelSums(currentNode->right, currentLevel + 1, levelSumMap);
    }

    int maxLevelSum(TreeNode* root) {

        // Map to store: level -> sum of node values at that level
        unordered_map<int, int> levelSumMap;

        // Populate level sums using DFS
        calculateLevelSums(root, 1, levelSumMap);

        // The answer must be the smallest level with maximum sum
        int bestLevel = 1;

        // Iterate through all levels
        for (const auto& entry : levelSumMap) {
            int level = entry.first;
            int levelSum = entry.second;

            // Update if we find a strictly larger sum
            // Or if sum is equal and we find a smaller level
            if (levelSum > levelSumMap[bestLevel] || (levelSum == levelSumMap[bestLevel] && level < bestLevel)) {
                bestLevel = level;
            }
        }

        return bestLevel;
    }
};

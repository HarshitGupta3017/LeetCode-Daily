// Solution for Maximum Product of Splitted Binary Tree in CPP

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    long long totalTreeSum = 0;   // Sum of all nodes in the tree
    long long maxProductValue = 0;

    // DFS to compute subtree sums and evaluate product when cutting an edge
    long long computeSubtreeSum(TreeNode* currentNode) {
        // Base case
        if (currentNode == nullptr) return 0;

        // Recursively compute left and right subtree sums
        long long leftSubtreeSum = computeSubtreeSum(currentNode->left);
        long long rightSubtreeSum = computeSubtreeSum(currentNode->right);

        // Sum of current subtree
        long long currentSubtreeSum =
            currentNode->val + leftSubtreeSum + rightSubtreeSum;

        // If we cut the edge above this subtree:
        // One part = currentSubtreeSum
        // Other part = totalTreeSum - currentSubtreeSum
        long long remainingSum = totalTreeSum - currentSubtreeSum;

        // Update maximum product
        maxProductValue = max(
            maxProductValue,
            currentSubtreeSum * remainingSum
        );

        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        if (root == nullptr) return 0;

        // First DFS: calculate total sum of the tree
        totalTreeSum = computeSubtreeSum(root);

        // Second DFS: try cutting every possible edge
        computeSubtreeSum(root);

        // Return result modulo after maximizing
        return maxProductValue % MOD;
    }
};

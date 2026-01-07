// Solution for Maximum Product of Splitted Binary Tree in JAVA

class Solution {

    private static final int MOD = 1_000_000_007;

    long totalTreeSum = 0;     // Sum of all nodes in the tree
    long maxProductValue = 0;

    // DFS to compute subtree sums and evaluate product when cutting an edge
    private long computeSubtreeSum(TreeNode currentNode) {

        // Base case
        if (currentNode == null) {
            return 0;
        }

        // Recursively compute left and right subtree sums
        long leftSubtreeSum = computeSubtreeSum(currentNode.left);
        long rightSubtreeSum = computeSubtreeSum(currentNode.right);

        // Sum of current subtree
        long currentSubtreeSum =
                currentNode.val + leftSubtreeSum + rightSubtreeSum;

        // Remaining tree sum if we cut above this subtree
        long remainingSum = totalTreeSum - currentSubtreeSum;

        // Update maximum product
        maxProductValue = Math.max(
                maxProductValue,
                currentSubtreeSum * remainingSum
        );

        return currentSubtreeSum;
    }

    public int maxProduct(TreeNode root) {
        if (root == null) return 0;

        // First DFS: compute total sum of the tree
        totalTreeSum = computeSubtreeSum(root);

        // Second DFS: compute max product by simulating cuts
        computeSubtreeSum(root);

        // Return result after modulo
        return (int) (maxProductValue % MOD);
    }
}

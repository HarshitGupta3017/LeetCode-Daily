// Solution for Sum of Root To Leaf Binary Numbers in JAVA

class Solution {
    private int solve(TreeNode root, int currentValue) {

        if (root == null)
            return 0;

        // Shift left and add current bit
        currentValue = (currentValue << 1) + root.val;

        // If leaf node
        if (root.left == null && root.right == null)
            return currentValue;

        // Recurse left and right
        return solve(root.left, currentValue)
             + solve(root.right, currentValue);
    }

    public int sumRootToLeaf(TreeNode root) {
        return solve(root, 0);
    }
}

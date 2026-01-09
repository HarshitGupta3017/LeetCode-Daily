// Solution for Smallest Subtree with all the Deepest Nodes in JAVA

class Solution {

    /*
        Helper class to store:
        - depth : maximum depth of the subtree
        - node  : smallest subtree containing all deepest nodes
    */
    private static class Result {
        int depth;
        TreeNode node;

        Result(int depth, TreeNode node) {
            this.depth = depth;
            this.node = node;
        }
    }

    private Result dfs(TreeNode node) {

        // Base case: empty subtree
        if (node == null) {
            return new Result(0, null);
        }

        // Recurse on left and right subtrees
        Result leftResult = dfs(node.left);
        Result rightResult = dfs(node.right);

        int leftDepth = leftResult.depth;
        int rightDepth = rightResult.depth;

        // If depths are equal, current node is LCA of deepest nodes
        if (leftDepth == rightDepth) {
            return new Result(leftDepth + 1, node);
        }

        // If left subtree is deeper
        if (leftDepth > rightDepth) {
            return new Result(leftDepth + 1, leftResult.node);
        }

        // Right subtree is deeper
        return new Result(rightDepth + 1, rightResult.node);
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).node;
    }
}

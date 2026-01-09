// Solution for Smallest Subtree with all the Deepest Nodes in CPP

class Solution {
public:
    /*
        Returns a pair:
        - first  -> maximum depth of the subtree rooted at 'node'
        - second -> the node which is the smallest subtree containing
                    all deepest nodes in this subtree
    */
    pair<int, TreeNode*> dfs(TreeNode* node) {
        // Base case: empty subtree
        if (!node) {
            return {0, nullptr};
        }

        // Recurse on left and right subtrees
        auto leftResult  = dfs(node->left);
        auto rightResult = dfs(node->right);

        int leftDepth  = leftResult.first;
        int rightDepth = rightResult.first;

        // If both subtrees have same maximum depth,
        // current node becomes the LCA of deepest nodes
        if (leftDepth == rightDepth) {
            return {leftDepth + 1, node};
        }

        // If left subtree is deeper, propagate its candidate
        if (leftDepth > rightDepth) {
            return {leftDepth + 1, leftResult.second};
        }

        // Otherwise, right subtree is deeper
        return {rightDepth + 1, rightResult.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};

// Solution for Sum of Root To Leaf Binary Numbers in CPP

class Solution {
public:

    /*
        DFS function.

        Parameters:
        - root : current node
        - currentValue : number formed so far
                         from root to parent
    */
    int solve(TreeNode* root, int currentValue) {

        // If node is null, no contribution
        if (!root)
            return 0;

        /*
            Update the current binary value.

            Multiply previous value by 2 (shift left),
            then add current node's bit (0 or 1).
        */
        currentValue = (currentValue * 2) + root->val;

        /*
            If this is a leaf node,
            return the complete binary number.
        */
        if (!root->left && !root->right)
            return currentValue;

        /*
            Otherwise, continue DFS
            and sum results from left and right subtrees.
        */
        return solve(root->left, currentValue)
             + solve(root->right, currentValue);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};

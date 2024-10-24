/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // simple ques, just need to check if 2 trees are equivalent or not
        // if both roots are null then they are equivalent
        if (!root1 && !root2) return true;
        // if any one is null and other is root then not equi
        if (!root1 || !root2) return false;
        // if value is not same then again not equivalent
        if (root1->val != root2->val) return false;
        // now we will just check before flipping and after it
        // without will be same as currently
        bool withoutflip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        // but after flip left node of first tree will be right of second one and vice versa
        bool withflip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return withoutflip || withflip;
    }
};

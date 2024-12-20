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

    void DFS(TreeNode* l, TreeNode* r, int level) {
        if (!l || !r) return;
        if (level % 2 == 1) swap(l->val, r->val);
        DFS(l->left, r->right, level + 1);
        DFS(l->right, r->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        // simple BFS/DFS based question
        // will use DFS here
        // just traverse in tree and if level is odd swap the values
        if (!root) return NULL;
        DFS(root->left, root->right, 1);
        return root;
    }
};

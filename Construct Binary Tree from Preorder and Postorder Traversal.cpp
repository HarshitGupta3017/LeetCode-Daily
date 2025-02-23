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

    unordered_map<int, int> mp;

    TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder) {
        if (prestart > preend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        if (prestart == preend) return root;
        int nextNode = preorder[prestart + 1];
        int j = mp[nextNode];
        int nodes = j - poststart + 1;
        root->left = solve(prestart + 1, poststart, prestart + nodes, preorder, postorder);
        root->right = solve(prestart + nodes + 1, j + 1, preend, preorder, postorder);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) mp[postorder[i]] = i;
        return solve(0, 0, n - 1, preorder, postorder);
    }
};

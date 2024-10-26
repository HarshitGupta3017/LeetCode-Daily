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
    vector<int> level, height, levelmaxh, levelsmaxh;

    // root and level 
    int computeLH(TreeNode* node, int l) {
        if (!node) return 0;
        level[node->val] = l;
        height[node->val] = max(computeLH(node->left, l + 1), computeLH(node->right, l + 1)) + 1;
        if (levelmaxh[l] < height[node->val]) {
            levelsmaxh[l] = levelmaxh[l];
            levelmaxh[l] = height[node->val];
        } else if (levelsmaxh[l] < height[node->val]) {
            levelsmaxh[l] = height[node->val];
        }
        return height[node->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        level = height = levelmaxh = levelsmaxh = vector<int>(100001, 0); // just resized all
        computeLH(root, 0);
        vector<int> res;
        for (const auto& q: queries) {
            int L = level[q];
            int ans = L + (levelmaxh[L] == height[q] ? levelsmaxh[L] : levelmaxh[L]) - 1;
            res.push_back(ans);
        }
        return res;
    }
};

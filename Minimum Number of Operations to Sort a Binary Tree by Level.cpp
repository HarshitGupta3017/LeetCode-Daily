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

    int solve(vector<int>& l) {
        // function to calculate total swaps
        // we can simply store elements with its indexes and sort that
        // and then we can transform sorted array into original one and calculate swaps
        int n = l.size();
        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; i++) sorted.push_back({l[i], i});
        sort(sorted.begin(), sorted.end());
        // now we can check if current index is equal to the index in the pair if yes 
        // then it is in correct position as in the original one otherwise we need to swap
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            // correct position
            if (sorted[i].second == i) continue;
            while (sorted[i].second != i) {
                // otherwise swap current one with the index in the pair 
                swap(sorted[i], sorted[sorted[i].second]);
                swaps++;
            }
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        // so a level based ques
        // can use BFS for level order
        int res = 0;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        // simple BFS template
        while(!q.empty()) {
            int n = q.size();
            vector<int> levelnodes;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                // storing in a vector to calculate total number of swaps
                levelnodes.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res += solve(levelnodes);
        }
        return res;
    }
};

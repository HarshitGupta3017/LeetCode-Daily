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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ls;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int cs = 0;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                cs += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ls.push_back(cs);
        }
        queue<TreeNode*> que;
        que.push(root);
        root->val = 0;
        int level = 0;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                TreeNode* node = que.front();
                que.pop();
                int child_sum = 0;
                if (node->left) child_sum += node->left->val;
                if (node->right) child_sum += node->right->val;
                if (node->left) {
                    node->left->val = ls[level + 1] - child_sum;
                    que.push(node->left);
                }
                if (node->right) {
                    node->right->val = ls[level + 1] - child_sum;
                    que.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};

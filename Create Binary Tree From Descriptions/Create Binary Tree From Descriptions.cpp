// Solution for Create Binary Tree From Descriptions in CPP

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        // Maps node value → TreeNode pointer
        // Reuse existing node if already created
        unordered_map<int, TreeNode*> nodeMap;

        // Tracks all values that appear as a child
        // Root will be the one value NOT in this set
        unordered_set<int> isChild;

        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal  = desc[1];
            int leftFlag  = desc[2];

            // Create parent node if not seen before
            if (!nodeMap.count(parentVal))
                nodeMap[parentVal] = new TreeNode(parentVal);

            // Create child node if not seen before
            if (!nodeMap.count(childVal))
                nodeMap[childVal] = new TreeNode(childVal);

            // Link child to parent (left or right)
            if (leftFlag == 1)
                nodeMap[parentVal]->left  = nodeMap[childVal];
            else
                nodeMap[parentVal]->right = nodeMap[childVal];

            // Mark this value as someone's child
            isChild.insert(childVal);
        }

        // Root = node that was never marked as a child
        for (auto& [val, node] : nodeMap) {
            if (!isChild.count(val))
                return node;
        }

        return nullptr;  // never reached (problem guarantees valid tree)
    }
};

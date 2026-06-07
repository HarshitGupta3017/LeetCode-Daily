// Solution for Create Binary Tree From Descriptions in JAVA

class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {

        // Maps node value -> TreeNode
        Map<Integer, TreeNode> nodeMap = new HashMap<>();

        // Stores values that appear as children
        Set<Integer> isChild = new HashSet<>();

        for (int[] desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int leftFlag = desc[2];

            // Create parent if not exists
            nodeMap.putIfAbsent(parentVal, new TreeNode(parentVal));

            // Create child if not exists
            nodeMap.putIfAbsent(childVal, new TreeNode(childVal));

            // Link child to parent
            if (leftFlag == 1) {
                nodeMap.get(parentVal).left = nodeMap.get(childVal);
            } else {
                nodeMap.get(parentVal).right = nodeMap.get(childVal);
            }

            // Mark as child
            isChild.add(childVal);
        }

        // Find root (node that is never a child)
        for (int val : nodeMap.keySet()) {
            if (!isChild.contains(val)) {
                return nodeMap.get(val);
            }
        }

        return null;
    }
}

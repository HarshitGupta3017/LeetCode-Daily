# Solution for Create Binary Tree From Descriptions in PY

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:

        # Maps node value -> TreeNode
        node_map = {}

        # Stores values that appear as children
        is_child = set()

        for parent_val, child_val, left_flag in descriptions:

            # Create parent if not exists
            if parent_val not in node_map:
                node_map[parent_val] = TreeNode(parent_val)

            # Create child if not exists
            if child_val not in node_map:
                node_map[child_val] = TreeNode(child_val)

            # Link child to parent
            if left_flag == 1:
                node_map[parent_val].left = node_map[child_val]
            else:
                node_map[parent_val].right = node_map[child_val]

            # Mark as child
            is_child.add(child_val)

        # Find root (node that never appears as a child)
        for val, node in node_map.items():
            if val not in is_child:
                return node

        return None

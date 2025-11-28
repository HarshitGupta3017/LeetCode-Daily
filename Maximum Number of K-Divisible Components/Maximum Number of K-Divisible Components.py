# Solution for Maximum Number of K-Divisible Components in PY

class Solution:
    # DFS function to compute subtree sums modulo k and count divisible components
    def dfs(self, node, parent, graph, values, k, component_count):
        # Start with current node's value
        subtree_sum_mod_k = values[node] % k

        # Explore neighbors (children in DFS)
        for neighbor in graph[node]:
            if neighbor == parent:
                continue  # Skip parent

            # Recursively compute child subtree sum
            child_sum_mod_k = self.dfs(neighbor, node, graph, values, k, component_count)

            # Add child's sum
            subtree_sum_mod_k = (subtree_sum_mod_k + child_sum_mod_k) % k

        # Check if this subtree forms a valid component
        if subtree_sum_mod_k == 0:
            component_count[0] += 1

        return subtree_sum_mod_k

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        
        # Build adjacency list
        graph = {i: [] for i in range(n)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        component_count = [0]  # Mutable counter for DFS

        # Run DFS from node 0
        self.dfs(0, -1, graph, values, k, component_count)

        return component_count[0]

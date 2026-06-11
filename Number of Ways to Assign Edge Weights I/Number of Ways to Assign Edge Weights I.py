# Solution for Number of Ways to Assign Edge Weights I in PY

class Solution:
    MOD = 10**9 + 7

    # Fast exponentiation: computes base^exp % MOD
    def power(self, base: int, exp: int) -> int:
        if exp == 0:
            return 1

        half = self.power(base, exp // 2)
        result = (half * half) % self.MOD

        if exp % 2 == 1:
            result = (result * base) % self.MOD

        return result

    # Returns maximum depth (in edges) from current node
    def getMaxDepth(self, adj, node, parent):
        max_child_depth = 0

        for neighbor in adj[node]:
            if neighbor == parent:
                continue

            max_child_depth = max(
                max_child_depth,
                self.getMaxDepth(adj, neighbor, node) + 1
            )

        return max_child_depth

    def assignEdgeWeights(self, edges):
        adj = defaultdict(list)

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        d = self.getMaxDepth(adj, 1, -1)

        return self.power(2, d - 1)

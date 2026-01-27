# Solution for Minimum Cost Path with Edge Reversals in PY

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:

        # Build adjacency list: node -> list of (neighbor, weight)
        adj = defaultdict(list)
        for u, v, w in edges:
            # Normal forward edge
            adj[u].append((v, w))
            # Switch-reversed edge with double cost
            adj[v].append((u, 2 * w))

        # Dijkstra's algorithm
        min_heap = [(0, 0)]  # (cost, node)
        min_dist = [float('inf')] * n
        min_dist[0] = 0

        while min_heap:
            curr_cost, curr_node = heapq.heappop(min_heap)

            if curr_node == n - 1:
                return curr_cost

            # Explore neighbors
            for neighbor, edge_cost in adj[curr_node]:
                new_cost = curr_cost + edge_cost
                if new_cost < min_dist[neighbor]:
                    min_dist[neighbor] = new_cost
                    heapq.heappush(min_heap, (new_cost, neighbor))

        return -1  # target unreachable

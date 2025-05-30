# Solution for Find Closest Node to Given Two Nodes in PY

class Solution:
    def computeDistancesFromNode(self, edges: List[int], start_node: int, total_nodes: int) -> List[int]:
        distance = [-1] * total_nodes
        distance[start_node] = 0

        queue = deque([start_node])

        while queue:
            current = queue.popleft()
            next_node = edges[current]
            if next_node != -1 and distance[next_node] == -1:
                distance[next_node] = distance[current] + 1
                queue.append(next_node)

        return distance

    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)

        dist1 = self.computeDistancesFromNode(edges, node1, n)
        dist2 = self.computeDistancesFromNode(edges, node2, n)

        min_max_dist = float('inf')
        closest_node = -1

        for i in range(n):
            if dist1[i] != -1 and dist2[i] != -1:
                max_dist = max(dist1[i], dist2[i])
                if max_dist < min_max_dist or (max_dist == min_max_dist and i < closest_node):
                    min_max_dist = max_dist
                    closest_node = i

        return closest_node

# Solution for Maximize the Number of Target Nodes After Connecting Trees I in PY

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        targetsFromTree1 = self.computeTargetNodesPerNode(edges1, k)
        targetsFromTree2 = self.computeTargetNodesPerNode(edges2, k - 1)
        maxTargetsInTree2 = max(targetsFromTree2)
        return [x + maxTargetsInTree2 for x in targetsFromTree1]

    def computeTargetNodesPerNode(self, edges: List[List[int]], maxDist: int) -> List[int]:
        totalNodes = len(edges) + 1
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return [self.BFS(i, adj, maxDist, totalNodes) for i in range(totalNodes)]

    def BFS(self, startNode: int, adj: dict, maxDist: int, totalNodes: int) -> int:
        q = deque([(startNode, 0)])
        visited = [False] * totalNodes
        visited[startNode] = True
        count = 0
        while q:
            node, dist = q.popleft()
            if dist > maxDist:
                continue
            count += 1
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    q.append((neighbor, dist + 1))
        return count

# Solution for Number of Ways to Arrive at Destination in PY

class Solution:
    MOD = 10**9 + 7
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        for u, v, time in roads:
            adj[u].append([v, time])
            adj[v].append([u, time])

        pq = []
        res = [sys.maxsize] * n
        pathCount = [0] * n
        res[0] = 0
        pathCount[0] = 1
        heapq.heappush(pq, (0, 0))
        
        while pq:
            currTime, currNode = heapq.heappop(pq)
            if currTime > res[currNode]:
                continue
            for ngbr, roadTime in adj[currNode]:
                if currTime + roadTime < res[ngbr]:
                    res[ngbr] = currTime + roadTime
                    heapq.heappush(pq, (res[ngbr], ngbr))
                    pathCount[ngbr] = pathCount[currNode]    
                elif currTime + roadTime == res[ngbr]:
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[currNode]) % self.MOD

        return pathCount[n - 1]

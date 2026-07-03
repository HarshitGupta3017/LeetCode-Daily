# Solution for Network Recovery Pathways in PY

class Solution:
    def canReachWithMinEdge(self, minEdge, n, k, adj):
        minCost = [inf] * n
        minCost[0] = 0

        pq = [(0, 0)]  # (cost, node)

        while pq:
            costSoFar, node = heappop(pq)

            if costSoFar > minCost[node]:
                continue

            if costSoFar > k:
                continue

            if node == n - 1:
                return True

            for neighbor, edgeCost in adj[node]:
                if edgeCost < minEdge:
                    continue

                newCost = costSoFar + edgeCost

                if newCost < minCost[neighbor]:
                    minCost[neighbor] = newCost
                    heappush(pq, (newCost, neighbor))

        return False

    def findMaxPathScore(self, edges, online, k):
        n = len(online)

        adj = defaultdict(list)

        lo = inf
        hi = 0

        for u, v, cost in edges:
            if not online[u] or not online[v]:
                continue

            adj[u].append((v, cost))

            lo = min(lo, cost)
            hi = max(hi, cost)

        if lo == inf:
            return -1

        ans = -1

        while lo <= hi:
            mid = (lo + hi) // 2

            if self.canReachWithMinEdge(mid, n, k, adj):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans

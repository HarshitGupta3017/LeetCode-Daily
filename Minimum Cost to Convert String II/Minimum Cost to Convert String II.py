# Solution for Minimum Cost to Convert String II in PY

class Solution:
    INF = 10**10

    def dijkstra(self, start, end, graph, dpDijkstra):
        if start in dpDijkstra and end in dpDijkstra[start]:
            return dpDijkstra[start][end]

        pq = [(0, start)]
        minCost = {start: 0}

        while pq:
            currCost, currStr = heapq.heappop(pq)

            if currCost > minCost[currStr]:
                continue
            if currStr == end:
                break

            for nxt, w in graph.get(currStr, []):
                newCost = currCost + w
                if nxt not in minCost or newCost < minCost[nxt]:
                    minCost[nxt] = newCost
                    heapq.heappush(pq, (newCost, nxt))

        res = minCost.get(end, self.INF)
        dpDijkstra.setdefault(start, {})[end] = res
        return res

    def solve(self, idx, source, target,
              graph, validLengths, dp, dpDijkstra):

        if idx == len(source):
            return 0
        if dp[idx] != -1:
            return dp[idx]

        ans = self.INF

        # Case 1: characters already equal
        if source[idx] == target[idx]:
            ans = self.solve(idx + 1, source, target,
                             graph, validLengths, dp, dpDijkstra)

        # Case 2: try substring transformations
        for length in validLengths:
            if idx + length > len(source):
                break

            srcSub = source[idx:idx + length]
            tgtSub = target[idx:idx + length]

            if srcSub not in graph:
                continue

            cost = self.dijkstra(srcSub, tgtSub, graph, dpDijkstra)
            if cost == self.INF:
                continue

            ans = min(ans,
                      cost + self.solve(idx + length, source, target,
                                        graph, validLengths, dp, dpDijkstra))

        dp[idx] = ans
        return ans

    def minimumCost(self, source: str, target: str,
                    original: List[str], changed: List[str],
                    cost: List[int]) -> int:

        graph = defaultdict(list)
        for o, c, w in zip(original, changed, cost):
            graph[o].append((c, w))

        validLengths = sorted(set(len(s) for s in original))

        dp = [-1] * len(source)
        dpDijkstra = {}

        res = self.solve(0, source, target,
                         graph, validLengths, dp, dpDijkstra)

        return -1 if res == self.INF else res

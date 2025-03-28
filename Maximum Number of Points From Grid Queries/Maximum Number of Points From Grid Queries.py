# Solution for Maximum Number of Points From Grid Queries in PY

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        m, n, q = len(grid), len(grid[0]), len(queries)
        res = [0] * q
        # sortedQ = []
        # for i in range(q):
        #     sortedQ.append([queries[i], i])
        # sortedQ.sort(key = lambda x: x[0])
        sortedQ = sorted([(queries[i], i) for i in range(q)], key = lambda x: x[0])

        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        minH = []
        vis = [[False] * n for _ in range(m)]
        points = 0

        heapq.heappush(minH, (grid[0][0], 0, 0))
        vis[0][0] = True

        for val, idx in sortedQ:
            while minH and minH[0][0] < val:
                _, i, j = heapq.heappop(minH)
                points += 1
                for dir in directions:
                    i_, j_ = i + dir[0], j + dir[1]
                    if 0 <= i_ < m and 0 <= j_ < n and not vis[i_][j_]:
                        heapq.heappush(minH, (grid[i_][j_], i_, j_))
                        vis[i_][j_] = True
            res[idx] = points

        return res

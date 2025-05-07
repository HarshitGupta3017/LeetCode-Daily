# Solution for Find Minimum Time to Reach Last Room I in PY

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        m, n = len(moveTime), len(moveTime[0])
        res = [[float('inf')] * n for _ in range(m)]
        res[0][0] = 0
        # Heap elements: (time, x, y)
        pq = [(0, 0, 0)]
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        while pq:
            curr_time, i, j = heapq.heappop(pq)
            if i == m - 1 and j == n - 1:
                return curr_time
            for dx, dy in directions:
                ni, nj = i + dx, j + dy
                if 0 <= ni < m and 0 <= nj < n:
                    wait = max(moveTime[ni][nj] - curr_time, 0)
                    arrival_time = curr_time + wait + 1
                    if res[ni][nj] > arrival_time:
                        res[ni][nj] = arrival_time
                        heapq.heappush(pq, (arrival_time, ni, nj))
        return -1

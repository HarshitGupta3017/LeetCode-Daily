# Solution for Swim in Rising Water in PY

class Solution:
    def swimInWater(self, grid):
        n = len(grid)
        visited = [[False] * n for _ in range(n)]

        # Min-heap storing (elevation, row, col)
        min_heap = [(grid[0][0], 0, 0)]
        visited[0][0] = True

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        min_time = 0

        while min_heap:
            curr_elev, r, c = heapq.heappop(min_heap)
            min_time = max(min_time, curr_elev)

            # If reached destination
            if r == n - 1 and c == n - 1:
                return min_time

            # Explore neighbors
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                    visited[nr][nc] = True
                    heapq.heappush(min_heap, (grid[nr][nc], nr, nc))

        return -1  # Should never reach here

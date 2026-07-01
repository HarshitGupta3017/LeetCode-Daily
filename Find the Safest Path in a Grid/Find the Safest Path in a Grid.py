# Solution for Find the Safest Path in a Grid in PY

class Solution:
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    # BFS from (0,0) to (n-1,n-1) using only cells whose distance
    # from the nearest thief is >= min_safeness.
    def canReachWithSafeness(self, distFromThief, min_safeness, n):
        if distFromThief[0][0] < min_safeness:
            return False

        visited = [[False] * n for _ in range(n)]
        queue = deque([(0, 0)])
        visited[0][0] = True

        while queue:
            row, col = queue.popleft()

            if row == n - 1 and col == n - 1:
                return True

            for dr, dc in self.directions:
                new_row = row + dr
                new_col = col + dc

                if not (0 <= new_row < n and 0 <= new_col < n):
                    continue
                if visited[new_row][new_col]:
                    continue
                if distFromThief[new_row][new_col] < min_safeness:
                    continue

                visited[new_row][new_col] = True
                queue.append((new_row, new_col))

        return False

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        distFromThief = [[-1] * n for _ in range(n)]
        visited = [[False] * n for _ in range(n)]
        queue = deque()

        # Multi-source BFS from all thief cells.
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j))
                    visited[i][j] = True
                    distFromThief[i][j] = 0

        dist = 0

        while queue:
            for _ in range(len(queue)):
                row, col = queue.popleft()

                distFromThief[row][col] = dist

                for dr, dc in self.directions:
                    new_row = row + dr
                    new_col = col + dc

                    if not (0 <= new_row < n and 0 <= new_col < n):
                        continue
                    if visited[new_row][new_col]:
                        continue

                    visited[new_row][new_col] = True
                    queue.append((new_row, new_col))

            dist += 1

        lo, hi = 0, 400
        ans = 0

        while lo <= hi:
            mid = (lo + hi) // 2

            if self.canReachWithSafeness(distFromThief, mid, n):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans

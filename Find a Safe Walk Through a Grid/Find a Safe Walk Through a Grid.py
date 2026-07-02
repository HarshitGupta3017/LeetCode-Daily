# Solution for Find a Safe Walk Through a Grid in PY

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])

        visited = [[0] * n for _ in range(m)]

        start_health = health - grid[0][0]
        if start_health <= 0:
            return False

        q = deque([(0, 0, start_health)])
        visited[0][0] = start_health

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            r, c, h = q.popleft()

            if r == m - 1 and c == n - 1:
                return True

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if not (0 <= nr < m and 0 <= nc < n):
                    continue

                nh = h - grid[nr][nc]

                if nh <= 0:
                    continue

                if visited[nr][nc] >= nh:
                    continue

                visited[nr][nc] = nh
                q.append((nr, nc, nh))

        return False

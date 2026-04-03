# Solution for Maximum Walls Destroyed by Robots in PY

class Solution:
    def countWalls(self, walls, l, r):
        return bisect.bisect_right(walls, r) - bisect.bisect_left(walls, l)

    def dfs(self, walls, robots, rng, i, prev, dp):
        if i == len(robots): return 0
        if dp[i][prev] != -1: return dp[i][prev]

        pos = robots[i][0]

        left_start = rng[i][0]
        if prev == 1 and i > 0:
            left_start = max(left_start, rng[i-1][1] + 1)

        left = self.countWalls(walls, left_start, pos) + \
               self.dfs(walls, robots, rng, i+1, 0, dp)

        right = self.countWalls(walls, pos, rng[i][1]) + \
                self.dfs(walls, robots, rng, i+1, 1, dp)

        dp[i][prev] = max(left, right)
        return dp[i][prev]

    def maxWalls(self, robotsPos, dist, walls):
        n = len(robotsPos)

        robots = sorted(zip(robotsPos, dist))
        walls.sort()

        rng = []
        for i in range(n):
            pos, d = robots[i]
            L = max(1 if i == 0 else robots[i-1][0] + 1, pos - d)
            R = min(int(1e9) if i == n-1 else robots[i+1][0] - 1, pos + d)
            rng.append((L, R))

        dp = [[-1]*2 for _ in range(n)]
        return self.dfs(walls, robots, rng, 0, 0, dp)

# Solution for Minimum Score Triangulation of Polygon in PY

class Solution:
    def solve(self, polygon, left, right, dp):
        # Base case: less than 3 vertices means no triangle can be formed
        if right - left + 1 < 3:
            return 0

        # Return memoized result if already computed
        if dp[left][right] != -1:
            return dp[left][right]

        min_score = float('inf')

        # Try all possible "middle" points to form a triangle (left, k, right)
        for k in range(left + 1, right):
            triangle_score = polygon[left] * polygon[right] * polygon[k]
            total_score = (self.solve(polygon, left, k, dp) +
                           triangle_score +
                           self.solve(polygon, k, right, dp))
            min_score = min(min_score, total_score)

        # Store result
        dp[left][right] = min_score
        return min_score

    def minScoreTriangulation(self, values):
        n = len(values)
        dp = [[-1] * n for _ in range(n)]
        return self.solve(values, 0, n - 1, dp)

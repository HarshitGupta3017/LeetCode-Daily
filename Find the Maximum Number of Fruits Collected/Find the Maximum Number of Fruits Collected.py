# Solution for Find the Maximum Number of Fruits Collected in PY

class Solution:
    def maxCollectedFruits(self, fruits: list[list[int]]) -> int:
        n = len(fruits)

        # Step 1: Child 1 collects from diagonal
        maxFruits = sum(fruits[i][i] for i in range(n))

        # Step 2: Prepare DP matrix
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if (i < j and i + j < n - 1) or (i > j and i + j < n - 1):
                    dp[i][j] = 0
                else:
                    dp[i][j] = fruits[i][j]

        # Step 3: Child 2 (above main diagonal: i < j)
        for i in range(1, n):
            for j in range(i + 1, n):
                from_top_left = dp[i - 1][j - 1] if j - 1 >= 0 else 0
                from_top = dp[i - 1][j]
                from_top_right = dp[i - 1][j + 1] if j + 1 < n else 0
                dp[i][j] += max(from_top_left, from_top, from_top_right)

        # Step 4: Child 3 (below main diagonal: i > j)
        for j in range(1, n):
            for i in range(j + 1, n):
                from_top_left = dp[i - 1][j - 1] if i - 1 >= 0 and j - 1 >= 0 else 0
                from_left = dp[i][j - 1]
                from_bottom_left = dp[i + 1][j - 1] if i + 1 < n and j - 1 >= 0 else 0
                dp[i][j] += max(from_top_left, from_left, from_bottom_left)

        # Step 5: Add all collected fruits
        return maxFruits + dp[n - 2][n - 1] + dp[n - 1][n - 2]

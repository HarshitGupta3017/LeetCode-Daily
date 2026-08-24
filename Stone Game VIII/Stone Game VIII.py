# Solution for Stone Game VIII in PY

class Solution:
    def stoneGameVIII(self, stones):
        n = len(stones)

        # prefix[i] = sum of stones[0..i]
        prefix = [0] * n
        prefix[0] = stones[0]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + stones[i]

        # dp[i] = best score difference from position i onward
        dp = [0] * n

        # Base case
        dp[n - 1] = prefix[n - 1]

        for i in range(n - 2, 0, -1):
            # Pick up to index i
            pick_here = prefix[i] - dp[i + 1]

            # Skip index i
            skip_here = dp[i + 1]

            dp[i] = max(pick_here, skip_here)

        # First move must take at least 2 stones
        return dp[1]

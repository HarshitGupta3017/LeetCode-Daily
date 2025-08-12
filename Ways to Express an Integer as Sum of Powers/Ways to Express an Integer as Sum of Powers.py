# Solution for Ways to Express an Integer as Sum of Powers in PY

class Solution:
    MOD = 10**9 + 7

    def countWays(self, remainingSum, currentBase, power, dp):
        # Base case: exact sum reached
        if remainingSum == 0:
            return 1
        # Sum exceeded
        if remainingSum < 0:
            return 0
        
        currentValue = currentBase ** power
        
        # If currentValue exceeds remainingSum, stop
        if currentValue > remainingSum:
            return 0
        
        # Memoization check
        if dp[remainingSum][currentBase] != -1:
            return dp[remainingSum][currentBase]
        
        # Include currentBase
        takeOption = self.countWays(remainingSum - currentValue, currentBase + 1, power, dp)
        # Skip currentBase
        skipOption = self.countWays(remainingSum, currentBase + 1, power, dp)
        
        dp[remainingSum][currentBase] = (takeOption + skipOption) % self.MOD
        return dp[remainingSum][currentBase]

    def numberOfWays(self, n: int, x: int) -> int:
        dp = [[-1] * (n + 1) for _ in range(n + 1)]
        return self.countWays(n, 1, x, dp)

# Solution for New 21 Game in PY

class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        dp = [0.0] * (n + 1)
        dp[0] = 1.0
        probWindowSum = 0 if k == 0 else 1
        
        for score in range(1, n + 1):
            dp[score] = probWindowSum / maxPts
            if score < k:
                probWindowSum += dp[score]
            if score - maxPts >= 0 and score - maxPts < k:
                probWindowSum -= dp[score - maxPts]
        
        return sum(dp[k:])

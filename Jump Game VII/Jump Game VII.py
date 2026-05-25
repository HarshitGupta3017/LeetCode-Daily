# Solution for Jump Game VII in PY

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        dp = [0] * n
        dp[0] = 1
        window = 0

        for i in range(1, n):
            if i - minJump >= 0:
                window += dp[i - minJump]
            if i - maxJump - 1 >= 0:
                window -= dp[i - maxJump - 1]

            if window > 0 and s[i] == '0':
                dp[i] = 1

        return dp[-1] == 1

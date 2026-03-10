# Solution for Find All Possible Stable Binary Arrays II in PY

class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:

        MOD = 10**9 + 7

        dp = [[[0]*2 for _ in range(one+1)] for _ in range(zero+1)]

        # Only zeros
        for z in range(min(zero, limit) + 1):
            dp[z][0][0] = 1

        # Only ones
        for o in range(min(one, limit) + 1):
            dp[0][o][1] = 1

        for z in range(zero + 1):
            for o in range(one + 1):

                if z == 0 or o == 0:
                    continue

                # End with 1
                dp[z][o][1] = (dp[z][o-1][0] + dp[z][o-1][1]) % MOD

                if o - 1 >= limit:
                    dp[z][o][1] = (dp[z][o][1] - dp[z][o-1-limit][0]) % MOD

                # End with 0
                dp[z][o][0] = (dp[z-1][o][0] + dp[z-1][o][1]) % MOD

                if z - 1 >= limit:
                    dp[z][o][0] = (dp[z][o][0] - dp[z-1-limit][o][1]) % MOD

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD

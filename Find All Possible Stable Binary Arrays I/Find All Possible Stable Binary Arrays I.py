# Solution for Find All Possible Stable Binary Arrays I in PY

class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:

        MOD = 10**9 + 7

        # dp[z][o][last]
        dp = [[[0] * 2 for _ in range(one + 1)] for _ in range(zero + 1)]

        # Base case
        dp[0][0][0] = 1
        dp[0][0][1] = 1

        for zeros_used in range(zero + 1):
            for ones_used in range(one + 1):

                if zeros_used == 0 and ones_used == 0:
                    continue

                ways = 0

                # CASE 1: last block was ones → place zeros
                for block_size in range(1, min(zeros_used, limit) + 1):
                    ways = (ways + dp[zeros_used - block_size][ones_used][0]) % MOD

                dp[zeros_used][ones_used][1] = ways

                ways = 0

                # CASE 2: last block was zeros → place ones
                for block_size in range(1, min(ones_used, limit) + 1):
                    ways = (ways + dp[zeros_used][ones_used - block_size][1]) % MOD

                dp[zeros_used][ones_used][0] = ways

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD

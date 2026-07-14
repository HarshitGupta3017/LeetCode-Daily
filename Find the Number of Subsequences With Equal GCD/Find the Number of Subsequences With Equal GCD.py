# Solution for Find the Number of Subsequences With Equal GCD in PY

class Solution:
    MOD = 10**9 + 7

    def subsequencePairCount(self, nums):
        n = len(nums)
        max_val = max(nums)

        dp = [[0] * (max_val + 1) for _ in range(max_val + 1)]

        # Base case
        for g in range(1, max_val + 1):
            dp[g][g] = 1

        for i in range(n - 1, -1, -1):
            nxt = [[0] * (max_val + 1) for _ in range(max_val + 1)]

            for g1 in range(max_val + 1):
                for g2 in range(max_val + 1):
                    skip = dp[g1][g2]
                    assign_to_seq1 = dp[gcd(g1, nums[i])][g2]
                    assign_to_seq2 = dp[g1][gcd(g2, nums[i])]

                    nxt[g1][g2] = (
                        skip + assign_to_seq1 + assign_to_seq2
                    ) % self.MOD

            dp = nxt

        return dp[0][0]

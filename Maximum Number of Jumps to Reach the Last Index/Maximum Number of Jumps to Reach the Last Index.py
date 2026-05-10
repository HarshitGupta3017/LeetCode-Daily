# Solution for Maximum Number of Jumps to Reach the Last Index in PY

class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:

        total_elements = len(nums)

        # dp[i] = maximum jumps required to reach index i
        # Initialize with -1 (unreachable)
        dp = [-1] * total_elements

        # Starting index requires 0 jumps
        dp[0] = 0

        # Try transitions from every reachable index
        for current_index in range(total_elements):

            # Skip unreachable states
            if dp[current_index] == -1:
                continue

            # Try jumping to all forward indices
            for next_index in range(current_index + 1, total_elements):

                # Valid jump condition
                if abs(nums[next_index] - nums[current_index]) <= target:
                    dp[next_index] = max(dp[next_index],
                                         dp[current_index] + 1)

        # Maximum jumps needed to reach last index
        return dp[-1]

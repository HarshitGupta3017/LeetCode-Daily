# Solution for Longest Balanced Subarray I in PY

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:

        n = len(nums)
        maxBalancedLength = 0

        # Fix the starting index
        for start in range(n):

            # Sets for DISTINCT evens and odds
            distinct_even = set()
            distinct_odd = set()

            # Extend subarray to the right
            for end in range(start, n):

                if nums[end] % 2 == 0:
                    distinct_even.add(nums[end])
                else:
                    distinct_odd.add(nums[end])

                # Check balanced condition
                if len(distinct_even) == len(distinct_odd):
                    maxBalancedLength = max(
                        maxBalancedLength,
                        end - start + 1
                    )

        return maxBalancedLength

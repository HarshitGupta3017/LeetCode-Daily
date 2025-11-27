# Solution for Maximum Subarray Sum With Length Divisible by K in PY

class Solution:
    def maxSubarraySum(self, nums, k):
        n = len(nums)

        # Prefix sum
        prefix = [0] * n
        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        best_result = float("-inf")

        # Try all starting indices modulo k
        for start_index in range(k):

            best_ending_here = 0   # Kadane on blocks
            i = start_index

            while i < n and (i + k - 1) < n:

                end_index = i + k - 1
                block_sum = prefix[end_index] - (prefix[i - 1] if i > 0 else 0)

                best_ending_here = max(block_sum, best_ending_here + block_sum)
                best_result = max(best_result, best_ending_here)

                i += k

        return best_result

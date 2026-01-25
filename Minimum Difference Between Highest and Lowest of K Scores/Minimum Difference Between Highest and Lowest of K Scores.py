# Solution for Minimum Difference Between Highest and Lowest of K Scores in PY

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:

        # If only one student is selected, difference is 0
        if k == 1:
            return 0

        # Sort the scores
        nums.sort()

        min_difference = float('inf')
        n = len(nums)

        # Sliding window of size k
        for start in range(n - k + 1):
            lowest_score = nums[start]
            highest_score = nums[start + k - 1]
            min_difference = min(min_difference, highest_score - lowest_score)

        return min_difference

# Solution for Smallest Stable Index II in PY

class Solution:
    def firstStableIndex(self, nums, k):
        n = len(nums)

        # suffix_minimum[i] = minimum value in nums[i..n-1]
        suffix_minimum = [0] * n

        current_minimum = float('inf')

        # Build suffix minimum from right to left.
        for index in range(n - 1, -1, -1):
            current_minimum = min(current_minimum, nums[index])
            suffix_minimum[index] = current_minimum

        # Maximum value in nums[0..index]
        current_maximum = float('-inf')

        # Scan from left to right to find the first stable index.
        for index in range(n):
            current_maximum = max(current_maximum, nums[index])

            suffix_min_value = suffix_minimum[index]

            # Instability score:
            # max(nums[0..index]) - min(nums[index..n-1])
            if current_maximum - suffix_min_value <= k:
                return index

        return -1

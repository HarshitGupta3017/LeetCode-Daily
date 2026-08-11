# Solution for Smallest Missing Integer Greater Than Sequential Prefix Sum in PY

class Solution:
    def missingInteger(self, nums):
        # Compute the sum of the longest sequential prefix.
        prefix_sum = nums[0]

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1] + 1:
                break
            prefix_sum += nums[i]

        # Store all values for O(1) average membership checks.
        present = set(nums)

        # Find the smallest integer >= prefix_sum not present in nums.
        while prefix_sum in present:
            prefix_sum += 1

        return prefix_sum

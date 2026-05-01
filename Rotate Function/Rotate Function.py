# Solution for Rotate Function in PY

class Solution:
    def maxRotateFunction(self, nums):
        n = len(nums)

        total_sum = 0
        current_value = 0  # F(0)

        # Step 1: Compute total sum and F(0)
        for i in range(n):
            total_sum += nums[i]
            current_value += i * nums[i]

        max_value = current_value

        # Step 2: Use recurrence relation
        for rotation in range(n):
            current_value = current_value + total_sum - n * nums[n - 1 - rotation]
            max_value = max(max_value, current_value)

        return max_value

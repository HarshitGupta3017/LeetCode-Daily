# Solution for Transformed Array in PY

class Solution:
    def constructTransformedArray(self, nums):
        n = len(nums)
        transformed_result = [0] * n

        for index in range(n):
            steps = nums[index] % n
            target_index = (index + steps) % n  # Python already handles negatives

            transformed_result[index] = nums[target_index]

        return transformed_result

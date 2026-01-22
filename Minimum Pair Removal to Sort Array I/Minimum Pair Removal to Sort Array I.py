# Solution for Minimum Pair Removal to Sort Array I in PY

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:

        def minIdx(arr):
            min_sum = float('inf')
            min_index = -1
            for i in range(len(arr) - 1):
                s = arr[i] + arr[i + 1]
                if s < min_sum:
                    min_sum = s
                    min_index = i
            return min_index

        operations = 0

        while nums != sorted(nums):
            idx = minIdx(nums)
            nums[idx] = nums[idx] + nums[idx + 1]
            nums.pop(idx + 1)
            operations += 1

        return operations

# Solution for Divide an Array Into Subarrays With Minimum Cost I in PY

class Solution:
    def minimumCost(self, nums: List[int]) -> int:

        # Cost of the first subarray (always nums[0])
        total_cost = nums[0]

        smallest = float('inf')
        second_smallest = float('inf')

        # Find two smallest values in nums[1:]
        for num in nums[1:]:
            if num < smallest:
                second_smallest = smallest
                smallest = num
            elif num < second_smallest:
                second_smallest = num

        return total_cost + smallest + second_smallest

# Solution for Trionic Array I in PY

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:

        n = len(nums)
        index = 0

        # Phase 1: Strictly Increasing
        while index + 1 < n and nums[index] < nums[index + 1]:
            index += 1

        # No increasing part OR reached the end
        if index == 0 or index == n - 1:
            return False

        # Phase 2: Strictly Decreasing
        while index + 1 < n and nums[index] > nums[index + 1]:
            index += 1

        # No final increasing phase
        if index == n - 1:
            return False

        # Phase 3: Strictly Increasing again
        while index + 1 < n and nums[index] < nums[index + 1]:
            index += 1

        return index == n - 1

# Solution for Check if Array Is Sorted and Rotated in PY

class Solution:
    def check(self, nums: List[int]) -> bool:
        return sum(nums[i] > nums[(i + 1) % len(nums)] for i in range(len(nums))) <= 1

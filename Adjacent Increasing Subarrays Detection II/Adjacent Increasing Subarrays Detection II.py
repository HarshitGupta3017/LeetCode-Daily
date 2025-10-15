# Solution for Adjacent Increasing Subarrays Detection II in PY

class Solution:
    def maxIncreasingSubarrays(self, nums: list[int]) -> int:
        prev = 0
        curr = 1
        max_k = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                curr += 1
            else:
                prev, curr = curr, 1
            max_k = max(max_k, curr // 2, min(prev, curr))
        return max_k

# Solution for Minimum Removals to Balance Array in PY

class Solution:
    def minRemoval(self, nums, k):
        nums.sort()
        left = 0
        best = 1

        for right in range(len(nums)):
            while nums[right] > k * nums[left]:
                left += 1
            best = max(best, right - left + 1)

        return len(nums) - best

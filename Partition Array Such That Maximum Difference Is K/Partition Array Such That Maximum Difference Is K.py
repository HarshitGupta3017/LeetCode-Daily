# Solution for Partition Array Such That Maximum Difference Is K in PY

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()

        minSubsequences = 1
        minInSubsequence = nums[0]

        for ele in nums:
            if ele - minInSubsequence > k:
                minSubsequences += 1
                minInSubsequence = ele

        return minSubsequences

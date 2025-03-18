# Solution for Longest Nice Subarray in PY

class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        n, i, j, mask, res = len(nums), 0, 0, 0, 1
        while j < n:
            while mask & nums[j] != 0:
                mask ^= nums[i]
                i += 1
            res = max(res, j - i + 1)
            mask |= nums[j]
            j += 1
        return res

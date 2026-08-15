# Solution for Longest Subsequence With Non-Zero Bitwise XOR in PY

class Solution:
    def longestSubsequence(self, nums):
        xor = 0
        for x in nums:
            xor ^= x

        if xor != 0:
            return len(nums)
        return 0 if all(x == 0 for x in nums) else len(nums) - 1

# Solution for Number of Zero-Filled Subarrays in PY

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        result = count = 0
        for num in nums:
            count = 0 if num != 0 else count + 1
            result += count
        return result

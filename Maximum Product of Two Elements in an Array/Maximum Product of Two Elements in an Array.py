# Solution for Maximum Product of Two Elements in an Array in PY

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        *_, a, b = sorted(nums)
        return (a - 1) * (b - 1)

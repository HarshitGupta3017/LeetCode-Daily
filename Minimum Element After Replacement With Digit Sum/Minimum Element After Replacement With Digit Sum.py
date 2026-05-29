# Solution for Minimum Element After Replacement With Digit Sum in PY

class Solution:
    def minElement(self, nums: List[int]) -> int:
        return min(sum(map(int, str(number))) for number in nums)

# Solution for Removing Minimum and Maximum From Array in PY

class Solution:
    def minimumDeletions(self, nums):
        n = len(nums)
        a = nums.index(min(nums))
        b = nums.index(max(nums))

        l, r = min(a, b), max(a, b)

        return min(r + 1, n - l, l + 1 + n - r)

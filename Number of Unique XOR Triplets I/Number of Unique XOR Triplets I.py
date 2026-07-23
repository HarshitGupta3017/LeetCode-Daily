# Solution for Number of Unique XOR Triplets I in PY

class Solution:
    def uniqueXorTriplets(self, nums):
        n = len(nums)
        if n <= 2:
            return n
        p = 1
        while p <= n:
            p <<= 1
        return p

# Solution for Smallest Missing Multiple of K in PY

class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        s = set(nums)
        candidate = k
        while candidate in s:
            candidate += k
        return candidate

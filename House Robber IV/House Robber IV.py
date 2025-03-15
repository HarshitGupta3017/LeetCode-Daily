# Solution for House Robber IV in PY

class Solution:

    def isPossible(self, nums: List[int], k: int, mid: int, n: int) -> bool:
        house, i = 0, 0
        while i < n:
            if nums[i] <= mid:
                house += 1    # included
                i += 1        # moved to i + 2
            i += 1
        return house >= k   # got atleast k houses

    def minCapability(self, nums: List[int], k: int) -> int:
        n, l, r = len(nums), min(nums), max(nums)
        res = r
        while l <= r:
            mid = l + (r - l) // 2      # capability
            if self.isPossible(nums, k, mid, n):
                res = mid
                r = mid - 1
            else:
                l = mid + 1
        return res

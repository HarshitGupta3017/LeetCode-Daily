# Solution for Maximum Candies Allocated to K Children in PY

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        l, r, res = 1, max(candies), 0
        while l <= r:
            mid = l + (r - l) // 2
            count = 0
            for c in candies:
                count += (c // mid)
                if count >= k: break
            if count >= k:
                res = mid
                l = mid + 1
            else:
                r = mid - 1
        return res

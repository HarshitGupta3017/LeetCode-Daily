# Solution for Minimum Time to Repair Cars in PY

class Solution:

    def isPossible(self, ranks: List[int], cars: int, mid: int) -> bool:
        carsFixed = 0
        for i in range(len(ranks)):
            carsFixed += isqrt(mid // ranks[i])
        return carsFixed >= cars

    def repairCars(self, ranks: List[int], cars: int) -> int:
        maxR = max(ranks)
        l, r, res = 1, maxR * cars * cars, -1
        while l <= r:
            mid = l + (r - l) // 2
            if self.isPossible(ranks, cars, mid):
                res = mid
                r = mid - 1
            else:
                l = mid + 1
        return res

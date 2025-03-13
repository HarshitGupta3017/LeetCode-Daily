# Solution for Zero Array Transformation II in PY

class Solution:

    def checkDiffArray(self, nums: List[int], queries: List[List[int]], k: int, n: int, q: int) -> bool:
        diff = [0] * n
        for i in range(k + 1):
            l, r, x = queries[i]
            diff[l] += x
            if r + 1 < n:
                diff[r + 1] -= x
        
        cumSum = 0
        for i in range(n):
            cumSum += diff[i]
            diff[i] = cumSum
            if nums[i] - diff[i] > 0:
                return False
        return True

    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n, q = len(nums), len(queries)
        if all(x == 0 for x in nums): 
            return 0
        l, r, k = 0, q - 1, -1
        while l <= r:
            mid = l + (r - l) // 2
            if self.checkDiffArray(nums, queries, mid, n, q):
                k = mid + 1
                r = mid - 1
            else:
                l = mid + 1
        return k

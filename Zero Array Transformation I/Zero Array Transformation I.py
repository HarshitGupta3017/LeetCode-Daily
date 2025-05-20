# Solution for Zero Array Transformation I in PY

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        diff = [0] * n
        for q in queries:
            start, end, x = q[0], q[1], 1
            diff[start] += 1
            if (end + 1 < n): 
                diff[end + 1] -= 1
        
        res = [0] * n
        cumSum = 0
        for i in range(n):
            cumSum += diff[i]
            res[i] = cumSum
        
        for i in range(n):
            if (res[i] < nums[i]):
                return False
        return True

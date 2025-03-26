# Solution for Minimum Operations to Make a Uni-Value Grid in PY

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []
        for row in grid:
            for col in row:
                nums.append(col)
        
        remainder = nums[0] % x
        for num in nums:
            if num % x != remainder:
                return -1
        
        nums.sort()
        ops = 0
        median = nums[len(nums) // 2]
        for num in nums:
            ops += abs(num - median) // x
    
        return ops

# Solution for Count Number of Maximum Bitwise-OR Subsets in PY

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        maxOr = 0
        for num in nums:
            maxOr |= num
        
        memo = [[-1] * (maxOr + 1) for _ in range(n + 1)]

        def solve(idx: int, currOr: int) -> int:
            if idx == n:
                return 1 if currOr == maxOr else 0
            if memo[idx][currOr] != -1:
                return memo[idx][currOr]

            take = solve(idx + 1, currOr | nums[idx])
            notTake = solve(idx + 1, currOr)
            memo[idx][currOr] = take + notTake
            return memo[idx][currOr]

        return solve(0, 0)

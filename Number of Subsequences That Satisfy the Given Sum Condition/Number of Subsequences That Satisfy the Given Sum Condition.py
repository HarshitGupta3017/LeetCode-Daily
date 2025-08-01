# Solution for Number of Subsequences That Satisfy the Given Sum Condition in PY

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        MOD = 10**9 + 7
        nums.sort()
        n = len(nums)

        power_of_two = [1] * n
        for i in range(1, n):
            power_of_two[i] = (power_of_two[i - 1] * 2) % MOD

        left, right = 0, n - 1
        total_valid = 0

        while left <= right:
            if nums[left] + nums[right] <= target:
                total_valid = (total_valid + power_of_two[right - left]) % MOD
                left += 1
            else:
                right -= 1

        return total_valid

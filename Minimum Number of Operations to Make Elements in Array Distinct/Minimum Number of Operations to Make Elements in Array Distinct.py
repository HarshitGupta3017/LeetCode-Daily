# Solution for Minimum Number of Operations to Make Elements in Array Distinct in PY

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        seen = [False] * 101
        for i in range(len(nums) - 1, -1, -1):
            if seen[nums[i]]: 
                return i // 3 + 1
            seen[nums[i]] = True
        return 0

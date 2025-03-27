# Solution for Minimum Index of a Valid Split in PY

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        mp1, mp2 = {}, {}
        for num in nums:
            mp2[num] = mp2.get(num, 0) + 1
        
        for i in range(n):
            num = nums[i]
            mp1[num] = mp1.get(num, 0) + 1
            mp2[num] -= 1
            n1, n2 = i + 1, n - i - 1
            if mp1[num] * 2 > n1 and mp2[num] * 2 > n2:
                return i

        return -1

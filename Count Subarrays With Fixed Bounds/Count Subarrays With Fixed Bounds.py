# Solution for Count Subarrays With Fixed Bounds in PY

class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        minKidx, maxKidx, culpritIdx, res = -1, -1, -1, 0
        for i in range(len(nums)):
            if (nums[i] < minK or nums[i] > maxK):
                culpritIdx = i
            if (nums[i] == minK):
                minKidx = i
            if (nums[i] == maxK):
                maxKidx = i
            smaller = min(maxKidx, minKidx)
            temp = smaller - culpritIdx
            res += 0 if (temp <= 0) else temp
        return res

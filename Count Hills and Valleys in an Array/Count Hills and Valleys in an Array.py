# Solution for Count Hills and Valleys in an Array in PY

class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        n = len(nums)
        i, j, count = 0, 1, 0
        while j + 1 < n:
            if ((nums[i] < nums[j] and nums[j] > nums[j + 1]) 
                    or 
                (nums[i] > nums[j] and nums[j] < nums[j + 1])
            ):
                count += 1
                i = j
            j += 1
        return count

# Solution for Sort Colors in PY

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j, k = 0, 0, len(nums) - 1
        while j <= k:
            if nums[j] == 1:
                j += 1
            elif nums[j] == 2:
                nums[j], nums[k] = nums[k], nums[j]
                k -= 1
            else:
                nums[j], nums[i] = nums[i], nums[j]
                i += 1
                j += 1

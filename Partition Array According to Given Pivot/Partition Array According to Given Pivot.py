# Solution for Partition Array According to Given Pivot in PY

class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        result = [0] * n

        left, right = 0, n - 1
        i, j = 0, n - 1

        while i < n and j >= 0:
            if nums[i] < pivot:
                result[left] = nums[i]
                left += 1

            if nums[j] > pivot:
                result[right] = nums[j]
                right -= 1

            i += 1
            j -= 1

        while left <= right:
            result[left] = pivot
            left += 1

        return result

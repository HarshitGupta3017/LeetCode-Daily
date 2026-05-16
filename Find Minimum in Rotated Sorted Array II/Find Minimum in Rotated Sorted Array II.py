# Solution for Find Minimum in Rotated Sorted Array II in PY

class Solution:
    def findMin(self, nums):

        left = 0
        right = len(nums) - 1

        # Store index of smallest element found so far
        minimum_index = 0

        while left <= right:

            # Remove duplicate values from left boundary
            while left < right and nums[left] == nums[left + 1]:
                left += 1

            # Remove duplicate values from right boundary
            while right > left and nums[right] == nums[right - 1]:
                right -= 1

            middle = left + (right - left) // 2

            # Update minimum element index if a smaller value is found
            if nums[middle] < nums[minimum_index]:
                minimum_index = middle

            # If middle element is greater than rightmost element,
            # rotation point must exist in the right half
            if nums[middle] > nums[right]:
                left = middle + 1

            # Otherwise, minimum lies in left half
            else:
                right = middle - 1

        return nums[minimum_index]

# Solution for Find Minimum in Rotated Sorted Array in PY

class Solution:
    def findMin(self, nums):
        left = 0
        right = len(nums) - 1

        # Perform binary search to locate the rotation point
        # (the smallest element in the rotated sorted array)
        while left < right:

            middle = left + (right - left) // 2

            # If middle element is greater than the rightmost element,
            # the minimum element must exist in the right portion
            # excluding middle itself
            if nums[middle] > nums[right]:

                left = middle + 1

            # Otherwise, the minimum element lies in the left portion,
            # and middle can still be the minimum candidate
            else:

                right = middle

        # At the end of binary search,
        # both pointers point to the minimum element
        return nums[left]

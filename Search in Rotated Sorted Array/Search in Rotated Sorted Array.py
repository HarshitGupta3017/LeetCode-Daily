# Solution for Search in Rotated Sorted Array in PY

class Solution:
    def search(self, nums, target):

        left = 0
        right = len(nums) - 1

        while left <= right:

            middle = left + (right - left) // 2

            # Target element found
            if nums[middle] == target:
                return middle

            # Check if left half is sorted
            if nums[left] <= nums[middle]:

                # Target exists inside sorted left half
                if nums[left] <= target < nums[middle]:
                    right = middle - 1

                # Otherwise search in right half
                else:
                    left = middle + 1

            # Right half is sorted
            else:

                # Target exists inside sorted right half
                if nums[middle] < target <= nums[right]:
                    left = middle + 1

                # Otherwise search in left half
                else:
                    right = middle - 1

        # Target not present
        return -1

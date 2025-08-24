# Solution for Longest Subarray of 1's After Deleting One Element in PY

class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        left = 0                   # Left pointer of sliding window
        max_length = 0             # Stores maximum window size
        zero_count = 0             # Count of zeros in current window

        # Traverse the array with right pointer
        for right in range(len(nums)):
            if nums[right] == 0:
                zero_count += 1    # Count zeros

            # Shrink window if more than one zero
            while zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1          # Move left pointer

            # Update max window length
            max_length = max(max_length, right - left + 1)

        # Subtract 1 because we must delete one element
        return max_length - 1

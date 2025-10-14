# Solution for Adjacent Increasing Subarrays Detection I in PY

class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)

        # freq[i] represents the length of the longest strictly increasing
        # subarray starting at index i.
        increasingLength = [1] * n

        # Traverse backward to fill increasingLength[]
        # If nums[i+1] > nums[i], it means we can extend the increasing sequence.
        for i in range(n - 2, -1, -1):
            if nums[i + 1] > nums[i]:
                increasingLength[i] = increasingLength[i + 1] + 1

        # Now, check for two *adjacent* subarrays of length k each
        # Subarray 1: starts at index a → nums[a ... a + k - 1]
        # Subarray 2: starts right after it → nums[a + k ... a + 2k - 1]
        for a in range(n - 2*k + 1):
            # If both subarrays starting at a and a + k are strictly increasing
            if increasingLength[a] >= k and increasingLength[a + k] >= k:
                return True

        # If no such pair of adjacent increasing subarrays found
        return False

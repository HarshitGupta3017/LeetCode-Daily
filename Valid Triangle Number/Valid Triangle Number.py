# Solution for Valid Triangle Number in PY

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()   # Step 1: sort the array
        totalTriangles = 0

        # Step 2: fix the largest side
        for largest in range(n - 1, 1, -1):
            left, right = 0, largest - 1

            # Step 3: two-pointer check
            while left < right:
                if nums[left] + nums[right] > nums[largest]:
                    totalTriangles += (right - left)
                    right -= 1
                else:
                    left += 1

        return totalTriangles

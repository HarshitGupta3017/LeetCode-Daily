# Solution for Distribute Elements Into Two Arrays I in PY

class Solution:
    def resultArray(self, nums):
        n = len(nums)

        result = [0] * n

        # nums[0] -> arr1, nums[1] -> arr2
        result[0] = nums[0]
        result[n - 1] = nums[1]

        frontTail = 0
        backTail = n - 1

        for i in range(2, n):
            if result[frontTail] > result[backTail]:
                # Append to arr1
                frontTail += 1
                result[frontTail] = nums[i]
            else:
                # Append to arr2
                backTail -= 1
                result[backTail] = nums[i]

        # Reverse arr2 to restore its original order
        result[backTail:] = result[backTail:][::-1]

        return result

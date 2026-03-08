# Solution for Find Unique Binary String in PY

class Solution:
    def findDifferentBinaryString(self, nums):
        """
        Construct a binary string that differs from
        every string in nums using Cantor's Diagonal Argument.
        """

        n = len(nums)
        different_string = []

        for i in range(n):
            # Flip the diagonal bit
            if nums[i][i] == '0':
                different_string.append('1')
            else:
                different_string.append('0')

        return ''.join(different_string)

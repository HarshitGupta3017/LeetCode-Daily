# Solution for The Two Sneaky Numbers of Digitville in PY

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        original_size = len(nums) - 2

        xor_all = 0
        for val in nums:
            xor_all ^= val

        for num in range(original_size):
            xor_all ^= num

        # Find rightmost set bit
        bit_mask = xor_all & -xor_all

        group1, group2 = 0, 0

        for val in nums:
            if val & bit_mask:
                group1 ^= val
            else:
                group2 ^= val

        for num in range(original_size):
            if num & bit_mask:
                group1 ^= num
            else:
                group2 ^= num

        return [group1, group2]

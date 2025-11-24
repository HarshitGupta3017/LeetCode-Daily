# Solution for Binary Prefix Divisible By 5 in PY

class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        result = []
        prefixMod = 0

        for bit in nums:
            prefixMod = ((prefixMod << 1) + bit) % 5
            result.append(prefixMod == 0)

        return result

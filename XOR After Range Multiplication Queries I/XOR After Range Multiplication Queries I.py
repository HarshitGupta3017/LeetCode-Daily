# Solution for XOR After Range Multiplication Queries I in PY

class Solution:
    def xorAfterQueries(self, nums, queries):
        MOD = 10**9 + 7

        # STEP 1: Process each query
        for leftIndex, rightIndex, stepSize, multiplier in queries:
            currentIndex = leftIndex

            while currentIndex <= rightIndex:
                nums[currentIndex] = (nums[currentIndex] * multiplier) % MOD
                currentIndex += stepSize

        # STEP 2: Compute XOR
        finalXOR = 0
        for value in nums:
            finalXOR ^= value

        return finalXOR

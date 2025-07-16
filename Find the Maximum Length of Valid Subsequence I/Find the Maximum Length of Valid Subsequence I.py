# Solution for Find the Maximum Length of Valid Subsequence I in PY

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        evenCount = 0
        oddCount = 0
        maxAlternatingLength = 1
        previousParity = nums[0] % 2

        if previousParity == 0:
            evenCount += 1
        else:
            oddCount += 1

        for i in range(1, len(nums)):
            currentParity = nums[i] % 2

            if currentParity != previousParity:
                maxAlternatingLength += 1
                previousParity = currentParity

            if currentParity == 0:
                evenCount += 1
            else:
                oddCount += 1

        return max(evenCount, oddCount, maxAlternatingLength)

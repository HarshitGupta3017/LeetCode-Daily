# Solution for Find Subsequence of Length K With the Largest Sum in PY

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums

        temp = sorted(nums, reverse=True)
        kthLargest = temp[k - 1]
        remainingKthCount = temp[:k].count(kthLargest)

        result = []
        for num in nums:
            if num > kthLargest:
                result.append(num)
            elif num == kthLargest and remainingKthCount > 0:
                result.append(num)
                remainingKthCount -= 1

            if len(result) == k:
                break

        return result

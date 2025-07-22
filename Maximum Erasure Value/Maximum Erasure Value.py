# Solution for Maximum Erasure Value in PY

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        cumSum = [0] * n
        cumSum[0] = nums[0]
        for i in range(1, n):
            cumSum[i] = cumSum[i - 1] + nums[i]
        
        left = right = maxScore = 0
        lastSeen = [-1] * 10001
        
        while right < n:
            left = max(left, lastSeen[nums[right]] + 1)
            currentSum = cumSum[right] - (cumSum[left - 1] if left > 0 else 0)
            maxScore = max(maxScore, currentSum)
            lastSeen[nums[right]] = right
            right += 1
        
        return maxScore

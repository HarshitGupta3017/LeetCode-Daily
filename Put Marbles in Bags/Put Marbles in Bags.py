# Solution for Put Marbles in Bags in PY

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        pairSum = [0] * (n - 1)
        for i in range(n - 1):
            pairSum[i] = weights[i] + weights[i + 1]
        pairSum.sort()
        minSum, maxSum = 0, 0
        for i in range(k - 1):
            minSum += pairSum[i]
            maxSum += pairSum[n - 1 - i - 1]
        return maxSum - minSum

# Solution for Divide an Array Into Subarrays With Minimum Cost II in PY

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:

        n = len(nums)

        minKElements = []        # sorted list of (value, index)
        remainingElements = []  # sorted list of (value, index)

        currentSum = 0
        right = 1

        # Initial window
        while right - dist < 1:
            bisect.insort(minKElements, (nums[right], right))
            currentSum += nums[right]

            if len(minKElements) > k - 1:
                val, idx = minKElements.pop()
                currentSum -= val
                bisect.insort(remainingElements, (val, idx))

            right += 1

        minCostForSubarrays = float('inf')

        # Sliding window
        while right < n:
            bisect.insort(minKElements, (nums[right], right))
            currentSum += nums[right]

            if len(minKElements) > k - 1:
                val, idx = minKElements.pop()
                currentSum -= val
                bisect.insort(remainingElements, (val, idx))

            minCostForSubarrays = min(minCostForSubarrays, currentSum)

            toRemove = (nums[right - dist], right - dist)

            pos = bisect.bisect_left(minKElements, toRemove)
            if pos < len(minKElements) and minKElements[pos] == toRemove:
                minKElements.pop(pos)
                currentSum -= toRemove[0]

                if remainingElements:
                    smallest = remainingElements.pop(0)
                    bisect.insort(minKElements, smallest)
                    currentSum += smallest[0]
            else:
                pos = bisect.bisect_left(remainingElements, toRemove)
                if pos < len(remainingElements) and remainingElements[pos] == toRemove:
                    remainingElements.pop(pos)

            right += 1

        return nums[0] + minCostForSubarrays

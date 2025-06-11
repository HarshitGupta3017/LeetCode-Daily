# Solution for Maximum Difference Between Even and Odd Frequency II in PY

class Solution:
    def getState(self, countA: int, countB: int) -> int:
        parityA = countA % 2
        parityB = countB % 2
        if parityA == 0 and parityB == 0:
            return 0
        if parityA == 0 and parityB == 1:
            return 1
        if parityA == 1 and parityB == 0:
            return 2
        return 3
        # return (parityA << 1) | parityB

    def maxDifference(self, s: str, k: int) -> int:
        n = len(s)
        maxDiff = float('-inf')

        for a in '01234':
            for b in '01234':
                if a == b:
                    continue

                minPrefixDiffForState = [float('inf')] * 4

                totalCountA = totalCountB = 0
                leftCountA = leftCountB = 0
                left = -1
                right = 0

                while right < n:
                    if s[right] == a:
                        totalCountA += 1
                    if s[right] == b:
                        totalCountB += 1

                    while right - left >= k and (totalCountB - leftCountB) >= 2 and (totalCountA - leftCountA) >= 1:
                        leftState = self.getState(leftCountA, leftCountB)
                        minPrefixDiffForState[leftState] = min(
                            minPrefixDiffForState[leftState],
                            leftCountA - leftCountB
                        )
                        left += 1
                        if left < n:
                            if s[left] == a:
                                leftCountA += 1
                            if s[left] == b:
                                leftCountB += 1

                    currentState = self.getState(totalCountA, totalCountB)
                    requiredPrevState = currentState ^ 2

                    if minPrefixDiffForState[requiredPrevState] != float('inf'):
                        diff = (totalCountA - totalCountB) - minPrefixDiffForState[requiredPrevState]
                        maxDiff = max(maxDiff, diff)

                    right += 1

        return maxDiff

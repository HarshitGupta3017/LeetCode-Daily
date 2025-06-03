# Solution for Distribute Candies Among Children II in PY

class Solution:
    def distributeCandies(self, totalCandies: int, limitPerChild: int) -> int:
        totalWays = 0

        minCandiesChild1 = max(0, totalCandies - 2 * limitPerChild)
        maxCandiesChild1 = min(totalCandies, limitPerChild)

        for candiesChild1 in range(minCandiesChild1, maxCandiesChild1 + 1):
            remainingCandies = totalCandies - candiesChild1

            minCandiesChild2 = max(0, remainingCandies - limitPerChild)
            maxCandiesChild2 = min(remainingCandies, limitPerChild)

            totalWays += (maxCandiesChild2 - minCandiesChild2 + 1)

        return totalWays

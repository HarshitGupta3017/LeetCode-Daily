# Solution for Candy in PY

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        totalCandies = n
        index = 1

        while index < n:
            if ratings[index] == ratings[index - 1]:
                index += 1
                continue

            uphillLength = 0
            while index < n and ratings[index] > ratings[index - 1]:
                uphillLength += 1
                totalCandies += uphillLength
                index += 1

            downhillLength = 0
            while index < n and ratings[index] < ratings[index - 1]:
                downhillLength += 1
                totalCandies += downhillLength
                index += 1

            totalCandies -= min(uphillLength, downhillLength)

        return totalCandies

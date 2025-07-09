# Solution for Reschedule Meetings for Maximum Free Time I in PY

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: list[int], endTime: list[int]) -> int:
        n = len(startTime)
        freeGaps = []

        freeGaps.append(startTime[0])
        for i in range(1, n):
            freeGaps.append(startTime[i] - endTime[i - 1])
        freeGaps.append(eventTime - endTime[-1])

        maxFree = 0
        currSum = 0
        left = 0

        for right in range(len(freeGaps)):
            currSum += freeGaps[right]

            while right - left + 1 > k + 1:
                currSum -= freeGaps[left]
                left += 1

            maxFree = max(maxFree, currSum)

        return maxFree

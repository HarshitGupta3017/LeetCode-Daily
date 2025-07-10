# Solution for Reschedule Meetings for Maximum Free Time II in PY

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        freeGaps = [0] * (n + 1)
        freeGaps[0] = startTime[0]

        for i in range(1, n):
            freeGaps[i] = startTime[i] - endTime[i - 1]

        freeGaps[n] = eventTime - endTime[-1]
        m = len(freeGaps)

        maxRightFree = [0] * m
        for i in range(m - 2, -1, -1):
            maxRightFree[i] = max(maxRightFree[i + 1], freeGaps[i + 1])

        maxFree = 0
        maxLeftFree = 0

        for i in range(1, m):
            meetingDuration = endTime[i - 1] - startTime[i - 1]

            if meetingDuration <= max(maxLeftFree, maxRightFree[i]):
                combinedFree = freeGaps[i - 1] + meetingDuration + freeGaps[i]
                maxFree = max(maxFree, combinedFree)

            maxFree = max(maxFree, freeGaps[i - 1] + freeGaps[i])
            maxLeftFree = max(maxLeftFree, freeGaps[i - 1])

        return maxFree

# Solution for Minimum Number of Seconds to Make Mountain Height Zero in PY

import math

class Solution:

    def canReduceMountain(self, timeLimit, mountainHeight, workerTimes):

        totalHeightReduced = 0

        for workerTime in workerTimes:

            # Maximum height this worker can reduce
            maxHeightByWorker = int(
                math.sqrt(2 * timeLimit / workerTime + 0.25) - 0.5
            )

            totalHeightReduced += maxHeightByWorker

            # Early stopping
            if totalHeightReduced >= mountainHeight:
                return True

        return totalHeightReduced >= mountainHeight


    def minNumberOfSeconds(self, mountainHeight, workerTimes):

        left = 1
        slowestWorkerTime = max(workerTimes)

        # Worst case: slowest worker removes whole mountain
        right = slowestWorkerTime * mountainHeight * (mountainHeight + 1) // 2

        minimumTime = 0

        while left <= right:

            midTime = (left + right) // 2

            if self.canReduceMountain(midTime, mountainHeight, workerTimes):

                minimumTime = midTime
                right = midTime - 1
            else:
                left = midTime + 1

        return minimumTime

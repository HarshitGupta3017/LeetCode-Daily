# Solution for Remove Covered Intervals in PY

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        # Sort by left endpoint ascending; if equal, right endpoint descending.
        intervals.sort(key=lambda x: (x[0], -x[1]))

        max_right = 0
        remaining = 0

        for left, right in intervals:
            if right > max_right:
                max_right = right
                remaining += 1

        return remaining

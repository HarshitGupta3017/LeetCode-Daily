# Solution for Set Intersection Size At Least Two in PY

class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:

        # Sort by end ASC, start DESC if end same
        intervals.sort(key=lambda x: (x[1], -x[0]))

        second_last = intervals[0][1] - 1
        last = intervals[0][1]

        selected_count = 2

        for i in range(1, len(intervals)):
            start, end = intervals[i]

            # Case 1: interval already contains both points
            if second_last >= start:
                continue

            # Case 2: interval contains only `last`
            elif last >= start:
                second_last = last
                last = end
                selected_count += 1

            # Case 3: contains none → add 2 new points
            else:
                second_last = end - 1
                last = end
                selected_count += 2

        return selected_count

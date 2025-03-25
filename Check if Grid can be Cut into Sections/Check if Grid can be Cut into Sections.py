# Solution for Check if Grid can be Cut into Sections in PY

class Solution:

    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x: x[0])
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            last = res[-1]
            if intervals[i][0] < last[1]:
                last[1] = max(intervals[i][1], last[1])
            else:
                res.append(intervals[i])
        return res

    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        x_axis, y_axis = [], []
        for rec in rectangles:
            x_axis.append([rec[0], rec[2]])
            y_axis.append([rec[1], rec[3]])
        mergedX = self.merge(x_axis)
        if len(mergedX) >= 3:
            return True
        mergedY = self.merge(y_axis)
        return len(mergedY) >= 3

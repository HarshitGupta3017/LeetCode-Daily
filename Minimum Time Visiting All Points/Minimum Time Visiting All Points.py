# Solution for Minimum Time Visiting All Points in PY

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        totalTime = 0
        for i in range(len(points) - 1):
            x1, y1 = points[i]
            x2, y2 = points[i + 1]
            
            dx = abs(x2 - x1)
            dy = abs(y2 - y1)
            
            totalTime += min(dx, dy) + abs(dx - dy)
        return totalTime

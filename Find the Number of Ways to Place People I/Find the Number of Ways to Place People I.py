# Solution for Find the Number of Ways to Place People I in PY

class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        n = len(points)
        result = 0

        # Sort by x ascending, if x same then y descending
        points.sort(key=lambda p: (p[0], -p[1]))

        for i in range(n):
            x1, y1 = points[i]
            max_y = float("-inf")  # track highest y seen so far for valid B

            for j in range(i + 1, n):
                x2, y2 = points[j]

                # Condition 1: A must be above B
                if y2 > y1:
                    continue

                # Condition 2: ensure no blocking point in between
                if y2 > max_y:
                    result += 1
                    max_y = y2

        return result

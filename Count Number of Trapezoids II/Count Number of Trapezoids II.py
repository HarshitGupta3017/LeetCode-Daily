# Solution for Count Number of Trapezoids II in PY

class Solution:
    def countTrapezoids(self, points):
        n = len(points)

        slope_to_intercepts = {}
        midpoint_to_slopes = {}

        # STEP 1: compute slope + intercept for each pair of points
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]

                dx = x2 - x1
                dy = y2 - y1

                if dx == 0:
                    slope = 1e18        # vertical special slope
                    intercept = x1
                else:
                    slope = dy / dx
                    intercept = (y1 * dx - x1 * dy) / dx

                mid_key = f"{x1 + x2}_{y1 + y2}"

                midpoint_to_slopes.setdefault(mid_key, []).append(slope)
                slope_to_intercepts.setdefault(slope, []).append(intercept)

        total = 0

        # STEP 2: count unordered pairs of parallel lines
        for intercept_list in slope_to_intercepts.values():

            if len(intercept_list) <= 1:
                continue

            freq = {}
            for b in intercept_list:
                freq[b] = freq.get(b, 0) + 1

            prefix = 0
            for key in sorted(freq.keys()):
                count = freq[key]
                total += count * prefix
                prefix += count

        # STEP 3: subtract collinear duplicates
        for slopes in midpoint_to_slopes.values():

            if len(slopes) <= 1:
                continue

            freq = {}
            for s in slopes:
                freq[s] = freq.get(s, 0) + 1

            prefix = 0
            for key in sorted(freq.keys()):
                count = freq[key]
                total -= count * prefix
                prefix += count

        return total

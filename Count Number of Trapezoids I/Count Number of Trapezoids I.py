# Solution for Count Number of Trapezoids I in PY

class Solution:
    def countTrapezoids(self, points):
        MOD = 10**9 + 7

        # Count points per y-coordinate
        points_at_y = {}
        for x, y in points:
            points_at_y[y] = points_at_y.get(y, 0) + 1

        total_trapezoids = 0
        accumulated_edges = 0

        for count_at_y in points_at_y.values():

            horizontal_edges = count_at_y * (count_at_y - 1) // 2

            total_trapezoids = (total_trapezoids +
                                (horizontal_edges % MOD) * (accumulated_edges % MOD)) % MOD

            accumulated_edges = (accumulated_edges + horizontal_edges) % MOD

        return total_trapezoids

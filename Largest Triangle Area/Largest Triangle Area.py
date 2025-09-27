# Solution for Largest Triangle Area in PY

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        
        max_area = 0.0

        # Step 1: Generate all unique triplets of points using itertools.combinations
        # Each triplet represents the vertices of a potential triangle
        for (x1, y1), (x2, y2), (x3, y3) in itertools.combinations(points, 3):

                    # Shoelace formula
                    area = 0.5 * abs(x1 * (y2 - y3) +
                                     x2 * (y3 - y1) +
                                     x3 * (y1 - y2))

                    max_area = max(max_area, area)

        return max_area

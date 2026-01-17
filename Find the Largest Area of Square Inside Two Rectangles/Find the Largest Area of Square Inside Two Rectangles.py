# Solution for Find the Largest Area of Square Inside Two Rectangles in PY

class Solution:
    def largestSquareArea(self, bottomLeft, topRight):

        rectangle_count = len(bottomLeft)
        max_square_side = 0

        """
        Check every unique rectangle pair.
        Compute intersection and largest square inside it.
        """
        for i in range(rectangle_count):
            for j in range(i + 1, rectangle_count):

                # Intersection width
                overlap_right_x = min(topRight[i][0], topRight[j][0])
                overlap_left_x  = max(bottomLeft[i][0], bottomLeft[j][0])
                overlap_width   = overlap_right_x - overlap_left_x

                # Intersection height
                overlap_top_y    = min(topRight[i][1], topRight[j][1])
                overlap_bottom_y = max(bottomLeft[i][1], bottomLeft[j][1])
                overlap_height   = overlap_top_y - overlap_bottom_y

                # Largest possible square side
                possible_square_side = min(overlap_width, overlap_height)

                max_square_side = max(max_square_side, possible_square_side)

        # Return area
        return max_square_side * max_square_side

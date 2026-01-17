// Solution for Find the Largest Area of Square Inside Two Rectangles in CPP

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        int rectangleCount = bottomLeft.size();
        int maxSquareSide = 0;

        /*
            We must consider intersections of AT LEAST two rectangles.
            Hence, we check every unique pair (i, j).

            For each pair:
            - Compute the intersection rectangle
            - Find the largest square that can fit inside that intersection
        */
        for (int i = 0; i < rectangleCount; i++) {
            for (int j = i + 1; j < rectangleCount; j++) {

                /*
                    Intersection width:
                    - Right boundary is the smaller of the two right edges
                    - Left boundary is the larger of the two left edges
                    If right <= left → no horizontal overlap
                */
                int overlapRightX = min(topRight[i][0], topRight[j][0]);
                int overlapLeftX  = max(bottomLeft[i][0], bottomLeft[j][0]);
                int overlapWidth  = overlapRightX - overlapLeftX;

                /*
                    Intersection height:
                    - Top boundary is the smaller of the two top edges
                    - Bottom boundary is the larger of the two bottom edges
                    If top <= bottom → no vertical overlap
                */
                int overlapTopY    = min(topRight[i][1], topRight[j][1]);
                int overlapBottomY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int overlapHeight  = overlapTopY - overlapBottomY;

                /*
                    The largest square inside a rectangle
                    is limited by its smaller dimension.
                */
                int possibleSquareSide = min(overlapWidth, overlapHeight);

                // Update global maximum square side
                maxSquareSide = max(maxSquareSide, possibleSquareSide);
            }
        }

        /*
            Problem asks for AREA, not side length.
            Use long long to avoid overflow.
        */
        return 1LL * maxSquareSide * maxSquareSide;
    }
};

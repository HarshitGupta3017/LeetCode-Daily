// Solution for Find the Largest Area of Square Inside Two Rectangles in JAVA

class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {

        int rectangleCount = bottomLeft.length;
        int maxSquareSide = 0;

        /*
            Check every unique pair of rectangles.
            Compute their intersection and find the largest
            square that can fit inside it.
        */
        for (int i = 0; i < rectangleCount; i++) {
            for (int j = i + 1; j < rectangleCount; j++) {

                // Intersection width
                int overlapRightX = Math.min(topRight[i][0], topRight[j][0]);
                int overlapLeftX  = Math.max(bottomLeft[i][0], bottomLeft[j][0]);
                int overlapWidth  = overlapRightX - overlapLeftX;

                // Intersection height
                int overlapTopY    = Math.min(topRight[i][1], topRight[j][1]);
                int overlapBottomY = Math.max(bottomLeft[i][1], bottomLeft[j][1]);
                int overlapHeight  = overlapTopY - overlapBottomY;

                // Largest square side inside the intersection
                int possibleSquareSide = Math.min(overlapWidth, overlapHeight);

                // Update maximum square side
                maxSquareSide = Math.max(maxSquareSide, possibleSquareSide);
            }
        }

        // Return AREA (use long to avoid overflow)
        return 1L * maxSquareSide * maxSquareSide;
    }
}

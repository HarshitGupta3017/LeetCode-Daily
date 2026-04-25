// Solution for Maximize the Distance Between Points on a Square in JAVA

class Solution {

    // Convert 2D boundary point into 1D position along square perimeter
    long mapToPerimeter(int sideLength, int x, int y) {
        if (y == 0) return x;                              // Bottom edge
        else if (x == sideLength) return sideLength + y;   // Right edge
        else if (y == sideLength) return 3L * sideLength - x; // Top edge
        return 4L * sideLength - y;                        // Left edge
    }

    // Check if we can place 'k' points such that minimum distance >= minDist
    boolean canPlacePoints(long[] extendedPositions,
                           int originalSize,
                           int requiredPoints,
                           int sideLength,
                           int minDist) {

        long perimeter = 4L * sideLength;

        // Try each position as starting point
        for (int startIndex = 0; startIndex < originalSize; startIndex++) {

            int selectedCount = 1;
            int currentIndex = startIndex;
            long lastPlacedPosition = extendedPositions[currentIndex];

            // Greedily place remaining points
            for (int step = 2; step <= requiredPoints; step++) {

                long nextRequiredPosition = lastPlacedPosition + minDist;

                // Binary search for next valid position
                int nextIndex = lowerBound(
                        extendedPositions,
                        currentIndex + 1,
                        startIndex + originalSize,
                        nextRequiredPosition
                );

                // No valid next point found
                if (nextIndex == startIndex + originalSize)
                    break;

                currentIndex = nextIndex;
                lastPlacedPosition = extendedPositions[currentIndex];
                selectedCount++;
            }

            // Check circular wrap-around constraint
            if (selectedCount == requiredPoints &&
                (extendedPositions[startIndex] + perimeter - lastPlacedPosition >= minDist)) {
                return true;
            }
        }

        return false;
    }

    // Custom lower_bound equivalent
    int lowerBound(long[] arr, int left, int right, long target) {
        int l = left, r = right;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    public int maxDistance(int side, int[][] points, int k) {

        int totalPoints = points.length;
        long perimeter = 4L * side;

        // Step 1: Map 2D points to 1D perimeter positions
        long[] perimeterPositions = new long[totalPoints];
        for (int i = 0; i < totalPoints; i++) {
            perimeterPositions[i] = mapToPerimeter(side, points[i][0], points[i][1]);
        }

        // Step 2: Sort positions
        Arrays.sort(perimeterPositions);

        // Step 3: Duplicate array to handle circular nature
        long[] extendedPositions = new long[2 * totalPoints];
        for (int i = 0; i < totalPoints; i++) {
            extendedPositions[i] = perimeterPositions[i];
            extendedPositions[i + totalPoints] = perimeterPositions[i] + perimeter;
        }

        // Step 4: Binary search on answer (minimum distance)
        int left = 0, right = 2 * side;
        int maximumMinimumDistance = 0;

        while (left <= right) {
            int midDistance = left + (right - left) / 2;

            if (canPlacePoints(extendedPositions, totalPoints, k, side, midDistance)) {
                maximumMinimumDistance = midDistance;
                left = midDistance + 1; // Try larger distance
            } else {
                right = midDistance - 1; // Reduce distance
            }
        }

        return maximumMinimumDistance;
    }
}

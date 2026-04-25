// Solution for Maximize the Distance Between Points on a Square in CPP

class Solution {
public:

    using ll = long long;

    // Convert 2D boundary point into 1D position along square perimeter
    ll mapToPerimeter(int sideLength, int x, int y) {
        if (y == 0) return x;                              // Bottom edge
        else if (x == sideLength) return sideLength + y;   // Right edge
        else if (y == sideLength) return 3LL * sideLength - x; // Top edge
        return 4LL * sideLength - y;                       // Left edge
    }

    // Check if we can place 'k' points such that minimum distance >= minDist
    bool canPlacePoints(vector<ll>& extendedPositions,
                        int originalSize,
                        int requiredPoints,
                        int sideLength,
                        int minDist) {

        ll perimeter = 4LL * sideLength;

        // Try each position as starting point
        for (int startIndex = 0; startIndex < originalSize; startIndex++) {

            int selectedCount = 1;
            int currentIndex = startIndex;
            ll lastPlacedPosition = extendedPositions[currentIndex];

            // Greedily place remaining points
            for (int step = 2; step <= requiredPoints; step++) {

                ll nextRequiredPosition = lastPlacedPosition + minDist;

                // Find next valid position using binary search
                auto it = lower_bound(
                    begin(extendedPositions) + currentIndex + 1,
                    begin(extendedPositions) + startIndex + originalSize,
                    nextRequiredPosition
                );

                // No valid next point found
                if (it == begin(extendedPositions) + startIndex + originalSize)
                    break;

                currentIndex = it - begin(extendedPositions);
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

    int maxDistance(int side, vector<vector<int>>& points, int k) {

        int totalPoints = points.size();
        ll perimeter = 4LL * side;

        // Step 1: Map 2D points to 1D perimeter positions
        vector<ll> perimeterPositions(totalPoints);
        for (int i = 0; i < totalPoints; i++) {
            perimeterPositions[i] = mapToPerimeter(side, points[i][0], points[i][1]);
        }

        // Step 2: Sort positions
        sort(begin(perimeterPositions), end(perimeterPositions));

        // Step 3: Duplicate array to handle circular nature
        vector<ll> extendedPositions(2 * totalPoints);
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
};

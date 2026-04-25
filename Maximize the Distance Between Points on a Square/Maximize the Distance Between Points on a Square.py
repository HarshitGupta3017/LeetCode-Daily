# Solution for Maximize the Distance Between Points on a Square in PY

class Solution:
    # Convert 2D boundary point into 1D position along square perimeter
    def mapToPerimeter(self, sideLength: int, x: int, y: int) -> int:
        if y == 0:
            return x                              # Bottom edge
        elif x == sideLength:
            return sideLength + y                 # Right edge
        elif y == sideLength:
            return 3 * sideLength - x             # Top edge
        return 4 * sideLength - y                 # Left edge

    # Check if we can place k points such that minimum distance >= minDist
    def canPlacePoints(self, extendedPositions, originalSize, requiredPoints, sideLength, minDist):
        perimeter = 4 * sideLength

        # Try each position as starting point
        for startIndex in range(originalSize):
            selectedCount = 1
            currentIndex = startIndex
            lastPlacedPosition = extendedPositions[currentIndex]

            # Greedily place remaining points
            for _ in range(1, requiredPoints):
                nextRequiredPosition = lastPlacedPosition + minDist

                # Binary search for next valid position
                nextIndex = bisect.bisect_left(
                    extendedPositions,
                    nextRequiredPosition,
                    currentIndex + 1,
                    startIndex + originalSize
                )

                # No valid next point found
                if nextIndex == startIndex + originalSize:
                    break

                currentIndex = nextIndex
                lastPlacedPosition = extendedPositions[currentIndex]
                selectedCount += 1

            # Check circular wrap-around constraint
            if (selectedCount == requiredPoints and
                extendedPositions[startIndex] + perimeter - lastPlacedPosition >= minDist):
                return True

        return False

    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        totalPoints = len(points)
        perimeter = 4 * side

        # Step 1: Map 2D points to 1D perimeter positions
        perimeterPositions = [
            self.mapToPerimeter(side, x, y) for x, y in points
        ]

        # Step 2: Sort positions
        perimeterPositions.sort()

        # Step 3: Duplicate array to handle circular nature
        extendedPositions = perimeterPositions + [p + perimeter for p in perimeterPositions]

        # Step 4: Binary search on answer (minimum distance)
        left, right = 0, 2 * side
        maximumMinimumDistance = 0

        while left <= right:
            midDistance = (left + right) // 2

            if self.canPlacePoints(extendedPositions, totalPoints, k, side, midDistance):
                maximumMinimumDistance = midDistance
                left = midDistance + 1  # Try larger distance
            else:
                right = midDistance - 1  # Reduce distance

        return maximumMinimumDistance

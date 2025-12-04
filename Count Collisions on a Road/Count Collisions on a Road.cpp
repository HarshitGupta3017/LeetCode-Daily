// Solution for Count Collisions on a Road in CPP

class Solution {
public:
    int countCollisions(string directions) {
        // Total number of cars
        int totalCars = directions.size();

        // ----------------------------------------------
        // STEP 1: Identify the first car from the left
        //         that is NOT moving left.
        // All 'L' cars on the far left escape safely.
        // ----------------------------------------------
        int leftIndex = 0;
        while (leftIndex < totalCars && directions[leftIndex] == 'L') {
            // These cars move left forever → no collisions
            leftIndex++;
        }

        // ----------------------------------------------
        // STEP 2: Identify the first car from the right
        //         that is NOT moving right.
        // All 'R' cars on the far right escape safely.
        // ----------------------------------------------
        int rightIndex = totalCars - 1;
        while (rightIndex >= 0 && directions[rightIndex] == 'R') {
            // These cars move right forever → no collisions
            rightIndex--;
        }

        // ----------------------------------------------
        // STEP 3: Count all cars between leftIndex and rightIndex
        //         that are NOT stationary.
        //
        // For any car in this middle block:
        //   - If it is 'R', it will collide with something on its right.
        //   - If it is 'L', it will collide with something on its left.
        //   - Only 'S' (stationary) cars do not actively cause collisions.
        //
        // Each non-'S' car will create exactly 1 collision in this region.
        // ----------------------------------------------
        int collisionCount = 0;
        while (leftIndex <= rightIndex) {
            if (directions[leftIndex] != 'S') {
                // This car will eventually crash → count it
                collisionCount++;
            }
            leftIndex++;
        }

        return collisionCount;
    }
};

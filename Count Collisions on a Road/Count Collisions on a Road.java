// Solution for Count Collisions on a Road in JAVA

class Solution {
    public int countCollisions(String directions) {
        int totalCars = directions.length();

        // Step 1: Skip all leading 'L' cars
        int leftIndex = 0;
        while (leftIndex < totalCars && directions.charAt(leftIndex) == 'L') {
            leftIndex++;
        }

        // Step 2: Skip all trailing 'R' cars
        int rightIndex = totalCars - 1;
        while (rightIndex >= 0 && directions.charAt(rightIndex) == 'R') {
            rightIndex--;
        }

        // Step 3: Count all non-'S' cars in the middle section
        int collisionCount = 0;
        while (leftIndex <= rightIndex) {
            if (directions.charAt(leftIndex) != 'S') {
                collisionCount++;
            }
            leftIndex++;
        }

        return collisionCount;
    }
}

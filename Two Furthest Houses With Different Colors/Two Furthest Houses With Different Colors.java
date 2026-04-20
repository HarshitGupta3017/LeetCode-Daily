// Solution for Two Furthest Houses With Different Colors in JAVA

class Solution {
    public int maxDistance(int[] colors) {
        int totalHouses = colors.length;
        int maximumDistance = 0;

        for (int currentIndex = 0; currentIndex < totalHouses; currentIndex++) {

            // Case 1: Compare with first house
            if (colors[currentIndex] != colors[0]) {
                maximumDistance = Math.max(maximumDistance, currentIndex);
            }

            // Case 2: Compare with last house
            if (colors[currentIndex] != colors[totalHouses - 1]) {
                maximumDistance = Math.max(maximumDistance, totalHouses - 1 - currentIndex);
            }
        }

        return maximumDistance;
    }
}

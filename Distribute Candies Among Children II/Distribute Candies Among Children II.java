// Solution for Distribute Candies Among Children II in JAVA

class Solution {
    public long distributeCandies(int totalCandies, int limitPerChild) {
        long totalWays = 0;

        int minCandiesChild1 = Math.max(0, totalCandies - 2 * limitPerChild);
        int maxCandiesChild1 = Math.min(totalCandies, limitPerChild);

        for (int candiesChild1 = minCandiesChild1; candiesChild1 <= maxCandiesChild1; candiesChild1++) {
            int remainingCandies = totalCandies - candiesChild1;

            int minCandiesChild2 = Math.max(0, remainingCandies - limitPerChild);
            int maxCandiesChild2 = Math.min(remainingCandies, limitPerChild);

            totalWays += (maxCandiesChild2 - minCandiesChild2 + 1);
        }

        return totalWays;
    }
}

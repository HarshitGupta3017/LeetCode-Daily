// Solution for Distribute Candies Among Children II in CPP

class Solution {
public:
    long long distributeCandies(int totalCandies, int limitPerChild) {
        long long totalWays = 0;

        // Loop through all possible candies for the first child (child1)
        // The minimum value for child1 is max(0, totalCandies - 2 * limit)
        // The maximum is min(totalCandies, limit)
        int minCandiesChild1 = max(0, totalCandies - 2 * limitPerChild);
        int maxCandiesChild1 = min(totalCandies, limitPerChild);

        for (int candiesChild1 = minCandiesChild1; candiesChild1 <= maxCandiesChild1; candiesChild1++) {
            int remainingCandies = totalCandies - candiesChild1;

            // Distribute remaining candies between child2 and child3
            // child2 gets between max(0, remaining - limit) and min(remaining, limit)
            int minCandiesChild2 = max(0, remainingCandies - limitPerChild);
            int maxCandiesChild2 = min(remainingCandies, limitPerChild);

            // Number of valid combinations for (child2, child3) is the count of values child2 can take
            // For each valid child2, child3 = remaining - child2 is automatically valid
            totalWays += (maxCandiesChild2 - minCandiesChild2 + 1);
        }

        return totalWays;
    }
};

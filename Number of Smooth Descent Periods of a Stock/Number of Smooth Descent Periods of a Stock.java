// Solution for Number of Smooth Descent Periods of a Stock in JAVA

class Solution {
    public long getDescentPeriods(int[] prices) {

        long totalDescentPeriods = 0L;
        long currentStreakLength = 1L; // single day is always valid

        for (int day = 1; day < prices.length; day++) {

            // Check smooth descent condition
            if (prices[day - 1] - prices[day] == 1) {
                currentStreakLength++;
            } else {
                // Add all subarrays from previous streak
                totalDescentPeriods += (currentStreakLength * (currentStreakLength + 1)) / 2;
                currentStreakLength = 1;
            }
        }

        // Add last streak contribution
        totalDescentPeriods += (currentStreakLength * (currentStreakLength + 1)) / 2;

        return totalDescentPeriods;
    }
}

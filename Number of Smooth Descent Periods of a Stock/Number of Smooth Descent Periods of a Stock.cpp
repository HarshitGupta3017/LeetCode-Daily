// Solution for Number of Smooth Descent Periods of a Stock in CPP

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        // This will store the final count of smooth descent periods
        long long totalDescentPeriods = 0;

        // Length of the current continuous smooth descent segment
        // A single day itself is a valid descent period
        long long currentStreakLength = 1;

        // Iterate through prices starting from the second day
        for (int day = 1; day < prices.size(); day++) {

            // Check if today's price is exactly 1 less than yesterday's price
            if (prices[day - 1] - prices[day] == 1) {
                // The smooth descent continues
                currentStreakLength++;
            } else {
                // The smooth descent breaks here
                // Add all subarrays formed by the previous descent streak
                totalDescentPeriods += (currentStreakLength * (currentStreakLength + 1)) / 2;

                // Reset streak length for the new segment
                currentStreakLength = 1;
            }
        }

        // Add the contribution of the last descent streak
        totalDescentPeriods += (currentStreakLength * (currentStreakLength + 1)) / 2;

        return totalDescentPeriods;
    }
};

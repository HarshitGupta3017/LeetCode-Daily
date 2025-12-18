// Solution for Best Time to Buy and Sell Stock using Strategy in JAVA

class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int totalDays = prices.length;

        // ---------------------------------------------
        // STEP 1: Compute base profit
        // ---------------------------------------------
        long baseProfit = 0;
        long[] dailyProfit = new long[totalDays];

        for (int day = 0; day < totalDays; day++) {
            dailyProfit[day] = (long) prices[day] * strategy[day];
            baseProfit += dailyProfit[day];
        }

        // ---------------------------------------------
        // STEP 2: Sliding window to find best modification
        // ---------------------------------------------
        long originalWindowProfit = 0;
        long modifiedWindowProfit = 0;
        long bestExtraGain = 0;

        int left = 0;

        for (int right = 0; right < totalDays; right++) {

            // Add original profit of current day
            originalWindowProfit += dailyProfit[right];

            // Second half of k-window becomes SELL (+price)
            if (right - left + 1 > k / 2) {
                modifiedWindowProfit += prices[right];
            }

            // Shrink window if size exceeds k
            if (right - left + 1 > k) {
                originalWindowProfit -= dailyProfit[left];
                modifiedWindowProfit -= prices[left + k / 2];
                left++;
            }

            // Evaluate gain when window size is exactly k
            if (right - left + 1 == k) {
                long currentGain = modifiedWindowProfit - originalWindowProfit;
                bestExtraGain = Math.max(bestExtraGain, currentGain);
            }
        }

        // ---------------------------------------------
        // STEP 3: Final result
        // ---------------------------------------------
        return baseProfit + bestExtraGain;
    }
}

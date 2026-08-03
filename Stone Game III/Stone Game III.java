// Solution for Stone Game III in JAVA

class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        // dp[i+1], dp[i+2], dp[i+3]
        int nextOne = 0, nextTwo = 0, nextThree = 0;

        for (int i = n - 1; i >= 0; i--) {
            int taken = stoneValue[i];

            // Take 1 stone
            int best = taken - nextOne;

            // Take 2 stones
            if (i + 2 <= n) {
                taken += stoneValue[i + 1];
                best = Math.max(best, taken - nextTwo);
            }

            // Take 3 stones
            if (i + 3 <= n) {
                taken += stoneValue[i + 2];
                best = Math.max(best, taken - nextThree);
            }

            // Shift the DP window
            nextThree = nextTwo;
            nextTwo = nextOne;
            nextOne = best;
        }

        if (nextOne > 0) return "Alice";
        if (nextOne < 0) return "Bob";
        return "Tie";
    }
}

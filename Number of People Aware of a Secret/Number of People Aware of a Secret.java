// Solution for Number of People Aware of a Secret in JAVA

class Solution {
    private static final int MOD = 1000000007;

    // Recursive helper with memoization
    private int countNewPeople(int day, int delay, int forget, int[] memo) {
        if (day == 1) return 1;  // Base case

        if (memo[day] != -1) return memo[day]; // Already computed

        int ways = 0;
        // Loop through all possible "starting days"
        for (int d = day - forget + 1; d <= day - delay; d++) {
            if (d > 0) {
                ways = (ways + countNewPeople(d, delay, forget, memo)) % MOD;
            }
        }

        return memo[day] = ways;
    }

    public int peopleAwareOfSecret(int n, int delay, int forget) {
        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);

        int total = 0;
        // Last window: only people who haven’t forgotten
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                total = (total + countNewPeople(day, delay, forget, memo)) % MOD;
            }
        }

        return total;
    }
}

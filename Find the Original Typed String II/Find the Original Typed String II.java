// Solution for Find the Original Typed String II in JAVA

class Solution {
    private static final int MOD = 1_000_000_007;

    public int possibleStringCount(String word, int k) {
        int n = word.length();
        if (k > n) return 0;

        // Step 1: Count consecutive character groups
        List<Integer> groupFreq = new ArrayList<>();
        int freq = 1;
        for (int i = 1; i < n; i++) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                freq++;
            } else {
                groupFreq.add(freq);
                freq = 1;
            }
        }
        groupFreq.add(freq);  // Last group

        int groupCount = groupFreq.size();

        // Step 2: Calculate total valid possibilities (product of group sizes)
        long totalWays = 1;
        for (int f : groupFreq) {
            totalWays = (totalWays * f) % MOD;
        }

        if (groupCount >= k) return (int) totalWays;

        // Step 3: Dynamic programming to subtract invalid combinations
        int[][] dp = new int[groupCount + 1][k + 1];

        for (int len = k - 1; len >= 0; len--) {
            dp[groupCount][len] = 1;
        }

        for (int i = groupCount - 1; i >= 0; i--) {
            int[] prefix = new int[k + 2];
            for (int j = 1; j <= k; j++) {
                prefix[j] = (prefix[j - 1] + dp[i + 1][j - 1]) % MOD;
            }

            for (int len = k - 1; len >= 0; len--) {
                int minLen = len + 1;
                int maxLen = len + groupFreq.get(i);
                if (maxLen >= k) maxLen = k - 1;

                if (minLen <= maxLen) {
                    dp[i][len] = (prefix[maxLen + 1] - prefix[minLen] + MOD) % MOD;
                }
            }
        }

        long invalidWays = dp[0][0];
        return (int) ((totalWays - invalidWays + MOD) % MOD);
    }
}

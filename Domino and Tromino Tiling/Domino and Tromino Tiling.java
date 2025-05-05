// Solution for Domino and Tromino Tiling in JAVA

class Solution {
    public int numTilings(int n) {
        int M = 1000000007;
        if (n == 1 || n == 2) return n;
        if (n == 3) return 5;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++) dp[i] = (2 * dp[i - 1] % M + dp[i - 3] % M) % M;
        return dp[n];  
    }
}

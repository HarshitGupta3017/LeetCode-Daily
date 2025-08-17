// Solution for New 21 Game in JAVA

class Solution {
    public double new21Game(int n, int k, int maxPts) {
        double[] dp = new double[n + 1];
        dp[0] = 1.0;
        double probWindowSum = (k == 0) ? 0 : 1;
        
        for (int score = 1; score <= n; score++) {
            dp[score] = probWindowSum / maxPts;
            if (score < k) probWindowSum += dp[score];
            if (score - maxPts >= 0 && score - maxPts < k) probWindowSum -= dp[score - maxPts];
        }
        
        double ans = 0.0;
        for (int i = k; i <= n; i++) ans += dp[i];
        return ans;
    }
}

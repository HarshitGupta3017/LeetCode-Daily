// Solution for Triangle in JAVA

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        
        int[] dp = new int[n];
        for (int col = 0; col <= n - 1; col++) {
            dp[col] = triangle.get(n - 1).get(col);
        }
        
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle.get(row).get(col) + Math.min(dp[col], dp[col + 1]);
            }
        }
    
        return dp[0];
    }
}

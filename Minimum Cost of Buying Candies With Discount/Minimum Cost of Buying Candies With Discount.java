// Solution for Minimum Cost of Buying Candies With Discount in JAVA

class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int totalCost = 0;

        for (int i = cost.length - 1, count = 0; i >= 0; i--, count++) {
            if (count % 3 != 2) totalCost += cost[i];
        }

        return totalCost;
    }
}

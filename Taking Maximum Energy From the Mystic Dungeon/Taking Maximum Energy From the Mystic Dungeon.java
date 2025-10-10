// Solution for Taking Maximum Energy From the Mystic Dungeon in JAVA

class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int totalMagicians = energy.length;
        int[] dp = new int[totalMagicians];
        Arrays.fill(dp, 0);
        int maxEnergyCollected = Integer.MIN_VALUE;

        // Process from right to left because dp[i] depends on dp[i + k]
        for (int index = totalMagicians - 1; index >= 0; index--) {
            int nextIndex = index + k;

            // If jumping goes out of bounds, only take current energy
            if (nextIndex >= totalMagicians)
                dp[index] = energy[index];
            else
                dp[index] = energy[index] + dp[nextIndex];

            // Track the best possible energy
            maxEnergyCollected = Math.max(maxEnergyCollected, dp[index]);
        }

        return maxEnergyCollected;
    }
}

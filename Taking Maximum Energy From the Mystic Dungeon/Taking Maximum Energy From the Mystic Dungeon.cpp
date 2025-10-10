// Solution for Taking Maximum Energy From the Mystic Dungeon in CPP

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int totalMagicians = energy.size();
        vector<int> dp(totalMagicians, 0);
        int maxEnergyCollected = INT_MIN;

        // Process from right to left because dp[i] depends on dp[i + k]
        for (int index = totalMagicians - 1; index >= 0; index--) {
            int nextIndex = index + k;

            // If jumping goes out of bounds, only take current energy
            if (nextIndex >= totalMagicians)
                dp[index] = energy[index];
            else
                dp[index] = energy[index] + dp[nextIndex];

            // Track the best possible energy
            maxEnergyCollected = max(maxEnergyCollected, dp[index]);
        }

        return maxEnergyCollected;
    }
};

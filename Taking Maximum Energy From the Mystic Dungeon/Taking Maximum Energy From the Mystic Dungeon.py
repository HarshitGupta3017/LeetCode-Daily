# Solution for Taking Maximum Energy From the Mystic Dungeon in PY

class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        totalMagicians = len(energy)
        dp = [0] * totalMagicians
        maxEnergyCollected = float(-inf)

        # Process from right to left because dp[i] depends on dp[i + k]
        for index in range(totalMagicians - 1, -1, -1):
            nextIndex = index + k

            # If jumping goes out of bounds, only take current energy
            if (nextIndex >= totalMagicians):
                dp[index] = energy[index]
            else:
                dp[index] = energy[index] + dp[nextIndex]

            # Track the best possible energy
            maxEnergyCollected = max(maxEnergyCollected, dp[index])

        return maxEnergyCollected

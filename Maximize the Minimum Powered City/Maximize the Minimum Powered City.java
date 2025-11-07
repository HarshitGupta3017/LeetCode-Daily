// Solution for Maximize the Minimum Powered City in JAVA

import java.util.*;

class Solution {
    // 🔹 Helper function to check if a target power level can be achieved
    private boolean canAchieveTarget(long targetPower, long[] diffArray, int r, int k, int n) {
        long currentPower = 0; // Accumulated power seen so far

        // Copy diff array to avoid mutation for other binary search iterations
        long[] diff = Arrays.copyOf(diffArray, diffArray.length);

        for (int i = 0; i < n; i++) {
            currentPower += diff[i];

            // If current city has less than required power
            if (currentPower < targetPower) {
                long needed = targetPower - currentPower;

                // Not enough extra stations to compensate
                if (needed > k) return false;

                // Use required stations
                k -= needed;
                currentPower += needed;

                // Cancel effect beyond influence range (city + 2*r)
                if (i + 2 * r + 1 < n)
                    diff[i + 2 * r + 1] -= needed;
            }
        }
        return true;
    }

    public long maxPower(int[] stations, int r, int k) {
        int n = stations.length;
        long[] diffArray = new long[n + 1];

        // Step 1️⃣: Build the initial difference array from station influence
        for (int i = 0; i < n; i++) {
            diffArray[Math.max(0, i - r)] += stations[i];
            if (i + r + 1 < n)
                diffArray[i + r + 1] -= stations[i];
        }

        // Step 2️⃣: Binary search range setup
        long left = Arrays.stream(stations).min().getAsInt();
        long right = Arrays.stream(stations).asLongStream().sum() + k;
        long best = 0;

        // Step 3️⃣: Binary search for maximum minimum power
        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (canAchieveTarget(mid, diffArray, r, k, n)) {
                best = mid;     // ✅ Achievable, try higher
                left = mid + 1;
            } else {
                right = mid - 1; // ❌ Not possible, go lower
            }
        }

        return best;
    }
}

// Solution for Maximum Running Time of N Computers in JAVA

import java.util.*;

class Solution {

    // Helper function to check if we can run all computers for 'targetTime' minutes
    private boolean canRunForTargetTime(int[] batteries, int computerCount, long targetTime) {
        long requiredTotalTime = targetTime * computerCount; // Total minutes needed
        long availableTime = 0;                               // Total minutes batteries can contribute

        for (int batteryCapacity : batteries) {
            // A battery can contribute at most targetTime
            availableTime += Math.min(batteryCapacity, targetTime);

            // If we already have enough total minutes, return true
            if (availableTime >= requiredTotalTime) {
                return true;
            }
        }

        return false; // Not enough total battery minutes
    }

    public long maxRunTime(int n, int[] batteries) {

        // Minimum possible time is the smallest battery
        long left = Arrays.stream(batteries).min().getAsInt();

        // Total sum of battery capacities
        long totalBatteryTime = 0;
        for (int b : batteries) totalBatteryTime += b;

        // Maximum possible time if we evenly distribute all battery time
        long right = totalBatteryTime / n;

        long bestPossibleTime = 0;

        // Binary search to find max run time
        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (canRunForTargetTime(batteries, n, mid)) {
                bestPossibleTime = mid;
                left = mid + 1; // Try bigger time
            } else {
                right = mid - 1; // Try smaller time
            }
        }

        return bestPossibleTime;
    }
}

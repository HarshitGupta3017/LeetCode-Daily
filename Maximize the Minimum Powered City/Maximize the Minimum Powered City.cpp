// Solution for Maximize the Minimum Powered City in CPP

class Solution {
public:
    using ll = long long;

    // 🔹 Helper function to check if it's possible to achieve at least 'targetPower' in every city
    bool canAchieveTarget(ll targetPower, vector<ll> diffArray, int range, int extraStations, int totalCities) {
        ll currentPower = 0;  // Current accumulated power (using prefix-sum style traversal)

        // Iterate through each city
        for (int city = 0; city < totalCities; city++) {
            currentPower += diffArray[city];  // Add effect of all stations affecting this city

            // If this city's power is below the target, we need to add extra stations
            if (currentPower < targetPower) {
                ll needed = targetPower - currentPower;  // How many more stations are required

                // If required stations exceed what we can still build → not feasible
                if (needed > extraStations) return false;

                // Deduct used stations from available pool
                extraStations -= needed;

                // Update this city's power immediately
                currentPower += needed;

                // The new stations affect up to (city + range) in both directions
                // So we cancel their effect beyond (city + 2*range)
                if (city + 2 * range + 1 < totalCities)
                    diffArray[city + 2 * range + 1] -= needed;
            }
        }

        // If we successfully processed all cities, this power level is achievable
        return true;
    }

    // 🔹 Main function to find the maximum possible minimum power across all cities
    // range: r, extraStations: k
    long long maxPower(vector<int>& stations, int range, int extraStations) {
        int totalCities = stations.size();

        // Step 1️⃣: Build difference array representing total power effect for each city
        vector<ll> diffArray(totalCities + 1, 0);

        // For each existing station, mark its influence range in the diff array
        for (int i = 0; i < totalCities; i++) {
            diffArray[max(0, i - range)] += stations[i];  // Start of influence
            if (i + range + 1 < totalCities)
                diffArray[i + range + 1] -= stations[i];  // End of influence
        }

        // Step 2️⃣: Define binary search range
        // The minimum power can’t be less than the smallest station count,
        // and maximum can’t exceed total stations + newly added ones
        ll left = *min_element(stations.begin(), stations.end());
        ll right = accumulate(stations.begin(), stations.end(), 0LL) + extraStations;
        ll bestPossible = 0;

        // Step 3️⃣: Binary search to maximize the minimum possible city power
        while (left <= right) {
            ll mid = left + (right - left) / 2;  // Midpoint power to test feasibility

            // Check if it's possible to ensure every city has at least 'mid' power
            if (canAchieveTarget(mid, diffArray, range, extraStations, totalCities)) {
                bestPossible = mid;       // ✅ Achievable — try for higher minimum power
                left = mid + 1;
            } else {
                right = mid - 1;          // ❌ Not achievable — reduce target power
            }
        }

        // Step 4️⃣: Return the highest achievable minimum power across all cities
        return bestPossible;
    }
};

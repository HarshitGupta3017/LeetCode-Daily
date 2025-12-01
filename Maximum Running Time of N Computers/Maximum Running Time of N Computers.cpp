// Solution for Maximum Running Time of N Computers in CPP

class Solution {
public:

    using ll = long long;

    // Helper function to check if we can run all computers for `targetTime` minutes
    bool canRunForTargetTime(vector<int>& batteries, int computerCount, ll targetTime) {

        ll requiredTotalTime = targetTime * computerCount;  // Total minutes needed
        ll availableTime = 0;                               // Total minutes batteries can contribute

        // Loop through each battery to accumulate possible minutes
        for (const auto& batteryCapacity : batteries) {

            // A battery can contribute at most targetTime (cannot give more than that per computer)
            availableTime += min((ll)batteryCapacity, targetTime);

            // If available time already meets or exceeds requirement, we succeed
            if (availableTime >= requiredTotalTime) {
                return true;
            }
        }

        // Not enough total battery minutes — cannot run that long
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        // We use binary search to find the maximum possible run time

        // Minimum possible time is the smallest battery capacity,
        // because no single battery can provide more minutes than it contains.
        ll left = *min_element(batteries.begin(), batteries.end());

        // Total sum of battery capacities
        ll totalBatteryTime = accumulate(batteries.begin(), batteries.end(), 0LL);

        // Maximum possible time if we evenly distribute all battery time
        ll right = totalBatteryTime / n;

        ll bestPossibleTime = 0;  // Stores the highest valid running time found so far

        // Binary search to find max run time
        while (left <= right) {

            ll mid = left + (right - left) / 2;  // Candidate running time

            // Check if running all computers for "mid" minutes is possible
            if (canRunForTargetTime(batteries, n, mid)) {

                bestPossibleTime = mid;   // Update result
                left = mid + 1;           // Try for a bigger value (maximize time)

            } else {

                right = mid - 1;          // Try smaller time values
            }
        }

        return bestPossibleTime;  // Maximum minutes all computers can run
    }
};

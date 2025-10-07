// Solution for Avoid Flood in The City in CPP

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        // Map to keep track of the last day each lake was filled
        unordered_map<int, int> lastRainDay;

        // Set to store indices of days where we have the option to dry a lake (rains[i] == 0)
        set<int> dryDays;

        // Result array to store the answer
        vector<int> result(n, 1);  // Default value for dry days; will update later

        for (int day = 0; day < n; day++) {
            int lake = rains[day];

            if (lake == 0) {
                // No rain today, we can dry a lake later
                dryDays.insert(day);
            } else {
                // It is raining on lake `lake` today
                result[day] = -1;  // By problem definition, raining days must be -1

                if (lastRainDay.count(lake)) {
                    // This lake has already been filled before
                    // We need to find a dry day after its last fill and before today
                    auto it = dryDays.lower_bound(lastRainDay[lake]);
                    
                    if (it == dryDays.end()) {
                        // No available dry day to empty this lake → flood occurs
                        return {};
                    }

                    // Assign this dry day to empty `lake` to avoid flood
                    int dryDay = *it;
                    result[dryDay] = lake;

                    // Remove this dry day from the set as it is now used
                    dryDays.erase(it);
                }

                // Update last day this lake was filled
                lastRainDay[lake] = day;
            }
        }

        // All days processed, return the result
        return result;
    }
};

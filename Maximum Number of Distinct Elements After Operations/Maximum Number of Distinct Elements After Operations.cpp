// Solution for Maximum Number of Distinct Elements After Operations in CPP

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Sort the array so we process elements in increasing order.
        sort(nums.begin(), nums.end());

        int distinctCount = 0;     // Tracks the number of unique values formed
        int lastUsed = INT_MIN;    // Stores the last assigned (distinct) value

        for (int i = 0; i < nums.size(); i++) {
            // The current number can be adjusted within [nums[i] - k, nums[i] + k]
            int minPossible = nums[i] - k;
            int maxPossible = nums[i] + k;

            /*
             * Case 1️⃣: If we can safely pick minPossible (no overlap with previous)
             * Example: previous chosen value = 3, minPossible = 5 → we can take 5.
             */
            if (lastUsed < minPossible) {
                lastUsed = minPossible;
                distinctCount++;
            }

            /*
             * Case 2️⃣: If minPossible would overlap but we can still shift within range
             * Example: lastUsed = 3, nums[i] = 3, k = 2 → range = [1,5].
             * We cannot take 1–3 again, but we can safely assign lastUsed + 1 = 4.
             */
            else if (lastUsed < maxPossible) {
                lastUsed++;
                distinctCount++;
            }

            // Else: cannot assign any new distinct number — skip
        }

        return distinctCount;
    }
};

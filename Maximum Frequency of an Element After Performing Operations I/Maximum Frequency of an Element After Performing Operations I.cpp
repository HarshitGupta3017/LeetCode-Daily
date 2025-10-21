// Solution for Maximum Frequency of an Element After Performing Operations I in CPP

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Step 1️⃣: Determine the highest possible value after adding up to +k to any element
        int maxPossibleValue = *max_element(nums.begin(), nums.end()) + k;

        // Step 2️⃣: Frequency array to count occurrences of each number
        vector<int> prefixFreq(maxPossibleValue + 1, 0);
        for (const int& value : nums) {
            prefixFreq[value]++;
        }

        // Step 3️⃣: Build prefix sum (cumulative sum) of frequencies for range-based  frequency queries
        for (int i = 1; i <= maxPossibleValue; i++) {
            prefixFreq[i] += prefixFreq[i - 1];
        }

        int maxFrequencyAfterOps = 0;

        // Step 4️⃣: Try making each possible number (target) as the most frequent element
        for (int targetValue = 0; targetValue <= maxPossibleValue; targetValue++) {
            // Skip if target value doesn’t exist in array
            if (prefixFreq[targetValue] == 0) continue;

            // Step 5️⃣: Compute valid range of numbers that can be converted to this target
            int leftRange = max(targetValue - k, 0);
            int rightRange = min(targetValue + k, maxPossibleValue);

            // Step 6️⃣: Count how many numbers fall within [targetValue - k, targetValue + k]
            int totalInRange = prefixFreq[rightRange] - (leftRange > 0 ? prefixFreq[leftRange - 1] : 0);

            // Step 7️⃣: Current frequency of the target value itself
            int currentTargetFreq = prefixFreq[targetValue] - (targetValue > 0 ? prefixFreq[targetValue - 1] : 0);

            // Step 8️⃣: Remaining numbers in range that can be adjusted using operations
            int convertibleElements = totalInRange - currentTargetFreq;

            // Step 9️⃣: Use as many operations as possible (but not more than available)
            int possibleConversions = min(convertibleElements, numOperations);

            // Step 🔟: Calculate total frequency achievable for this target value
            int combinedFrequency = currentTargetFreq + possibleConversions;

            // Update the maximum achievable frequency
            maxFrequencyAfterOps = max(maxFrequencyAfterOps, combinedFrequency);
        }

        return maxFrequencyAfterOps;
    }
};

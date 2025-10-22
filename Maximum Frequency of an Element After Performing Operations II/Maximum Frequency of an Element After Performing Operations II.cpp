// Solution for Maximum Frequency of an Element After Performing Operations II in CPP

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        // Step 1️⃣: Calculate the highest possible number after adding +k to any element
        int maxPossibleValue = *max_element(nums.begin(), nums.end()) + k;

        // Step 2️⃣: Initialize data structures
        // diffMap → stores the difference array (range updates via prefix sum logic)
        // originalFreq → stores the frequency of each number as-is
        map<int, int> diffMap; 
        unordered_map<int, int> originalFreq; 

        // Step 3️⃣: Build the difference map for all ranges [value - k, value + k]
        // Each number contributes to a range of possible target values it can reach
        for (const int& value : nums) {
            originalFreq[value]++;                           // Track current frequency of number
            int leftBound = max(value - k, 0);               // Minimum reachable value
            int rightBound = value + k;                      // Maximum reachable value

            diffMap[leftBound]++;                            // Start of range
            diffMap[rightBound + 1]--;                       // End of range
            diffMap[value] += 0;                             // Ensure current value appears in map
        }

        int maxAchievableFrequency = 1;  // Stores the best frequency found
        int prefixSum = 0;               // Running cumulative sum for range contributions

        // Step 4️⃣: Traverse all possible target values in sorted order (map keeps keys sorted)
        for (auto& [targetValue, diffValue] : diffMap) {

            // Step 5️⃣: Apply prefix sum to find how many elements can reach this target
            diffValue += prefixSum;

            // Step 6️⃣: Retrieve frequency of target value itself (if it exists)
            int currentTargetFreq = originalFreq[targetValue];

            // Step 7️⃣: Compute how many other elements can be converted to this target
            int convertibleElements = diffValue - currentTargetFreq;

            // Step 8️⃣: Use operations on as many convertible elements as possible
            int usedOperations = min(numOperations, convertibleElements);

            // Step 9️⃣: Total frequency after conversions
            int totalFrequency = currentTargetFreq + usedOperations;

            // Step 🔟: Update maximum frequency found so far
            maxAchievableFrequency = max(maxAchievableFrequency, totalFrequency);

            // Step 1️⃣1️⃣: Update prefix sum for next iteration
            prefixSum = diffValue;
        }

        return maxAchievableFrequency;
    }
};

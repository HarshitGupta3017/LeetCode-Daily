// Solution for Maximize Subarrays After Removing One Conflicting Pair in CPP

#define ALL(x) begin(x), end(x) 

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // Step 1: Map conflict relationships.
        // For each number i, store the list of numbers smaller than i that conflict with i
        vector<vector<int>> conflictWithLeft(n + 1);  // conflictWithLeft[i] = list of j where [j, i] is a conflict

        for (const auto& pair : conflictingPairs) {
            int a = pair[0];
            int b = pair[1];
            int larger = max(a, b);  // Ensure consistent direction (left < right)
            int smaller = min(a, b);
            conflictWithLeft[larger].push_back(smaller);
        }

        // Step 2: Variables for tracking conflict limits
        int maxLeft = 0;          // Furthest left conflict that affects the current subarray end
        int secondMaxLeft = 0;    // Second furthest left conflict (for extra gain calc)
        long long validSubarrays = 0;    // Total valid subarrays count
        vector<long long> extraGain(n + 1, 0); // Potential extra subarrays if a certain conflict is removed

        // Step 3: Sweep the array from left to right
        for (int end = 1; end <= n; end++) {
            // Update conflict bounds for subarrays ending at position `end`
            for (int leftConflict : conflictWithLeft[end]) {
                if (leftConflict >= maxLeft) {
                    // New max becomes secondMax
                    secondMaxLeft = maxLeft;
                    maxLeft = leftConflict;
                } else if (leftConflict > secondMaxLeft) {
                    secondMaxLeft = leftConflict;
                }
            }

            // For each end index, subarrays starting after maxLeft are valid
            // So we add (end - maxLeft) valid subarrays
            validSubarrays += (end - maxLeft);

            // Store how many extra subarrays can be gained if the maxLeft conflict is removed
            extraGain[maxLeft] += (maxLeft - secondMaxLeft);
        }

        // Step 4: Add the maximum possible extra gain by removing one conflict
        return validSubarrays + *max_element(ALL(extraGain));
    }
};

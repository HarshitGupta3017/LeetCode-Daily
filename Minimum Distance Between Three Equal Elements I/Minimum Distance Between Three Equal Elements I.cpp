// Solution for Minimum Distance Between Three Equal Elements I in CPP

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Map each value to the list of indices where it appears
        unordered_map<int, vector<int>> valueToIndices;

        for (int index = 0; index < nums.size(); index++) {
            valueToIndices[nums[index]].push_back(index);
        }

        int minimumDistance = INT_MAX;

        // Iterate over each unique value and its corresponding indices
        for (auto& entry : valueToIndices) {
            vector<int>& indices = entry.second;

            // We need at least 3 occurrences to form a valid tuple
            if (indices.size() < 3) continue;

            /*
             * For any triplet (i, j, k) with i < j < k:
             * distance = |i - j| + |j - k| + |k - i|
             *          = 2 * (k - i)
             *
             * To minimize this, we check consecutive triplets
             * and minimize (indices[right] - indices[left]).
             */
            for (int left = 0; left + 2 < indices.size(); left++) {
                int right = left + 2;

                int currentDistance = 2 * (indices[right] - indices[left]);
                minimumDistance = min(minimumDistance, currentDistance);
            }
        }

        // If no valid triplet was found, return -1
        return (minimumDistance == INT_MAX) ? -1 : minimumDistance;
    }
};

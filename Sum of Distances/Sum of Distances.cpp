// Solution for Sum of Distances in CPP

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        int n = nums.size();

        // Map each value -> list of indices where it appears
        unordered_map<int, vector<int>> valueToIndices;

        for (int index = 0; index < n; index++) {
            valueToIndices[nums[index]].push_back(index);
        }

        // Final result array
        vector<long long> distanceSum(n, 0);

        // Process each group of equal values independently
        for (auto& [value, indicesList] : valueToIndices) {

            int groupSize = indicesList.size();

            // Prefix sum of indices to allow O(1) range sum queries
            vector<long long> prefixIndicesSum(groupSize, 0);
            prefixIndicesSum[0] = indicesList[0];

            for (int i = 1; i < groupSize; i++) {
                prefixIndicesSum[i] = prefixIndicesSum[i - 1] + indicesList[i];
            }

            // For each occurrence of the value
            for (int i = 0; i < groupSize; i++) {

                int currentIndex = indicesList[i];

                // -----------------------
                // LEFT SIDE CONTRIBUTION
                // -----------------------
                // All indices before i (i.e., 0 to i-1)
                // Formula: sum(currentIndex - indices[j]) for j < i

                long long leftContribution = 0;

                if (i > 0) {
                    // i elements on left
                    // total distance = i * currentIndex - sum(indices[0...i-1])
                    leftContribution = (long long)i * currentIndex - prefixIndicesSum[i - 1];
                }

                // ------------------------
                // RIGHT SIDE CONTRIBUTION
                // ------------------------
                // All indices after i (i.e., i+1 to end)
                // Formula: sum(indices[j] - currentIndex) for j > i

                long long rightContribution = 0;

                if (i < groupSize - 1) {
                    // number of elements on right
                    int rightCount = groupSize - i - 1;

                    // sum(indices[i+1 ... end])
                    long long rightSum = prefixIndicesSum[groupSize - 1] - prefixIndicesSum[i];

                    // total distance = sum(indices[j]) - rightCount * currentIndex
                    rightContribution = rightSum - (long long)rightCount * currentIndex;
                }

                // Total distance for this index
                distanceSum[currentIndex] = leftContribution + rightContribution;
            }
        }

        return distanceSum;
    }
};

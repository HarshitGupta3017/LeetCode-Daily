// Solution for Closest Equal Element Queries in CPP

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        int arraySize = nums.size();

        // Map each value -> list of indices where it appears
        unordered_map<int, vector<int>> valueToIndicesMap;

        // Build the mapping
        for (int index = 0; index < arraySize; index++) {
            valueToIndicesMap[nums[index]].push_back(index);
        }

        vector<int> answer;

        // Process each query independently
        for (int queryIndex : queries) {

            int currentValue = nums[queryIndex];

            // Get all positions where this value occurs
            vector<int>& occurrenceIndices = valueToIndicesMap[currentValue];

            // If value appears only once, no valid answer
            if (occurrenceIndices.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            int occurrencesCount = occurrenceIndices.size();

            // Find the position of queryIndex in the sorted occurrences list
            // lower_bound gives first index >= queryIndex
            int positionInList = lower_bound(occurrenceIndices.begin(), occurrenceIndices.end(),
                                    queryIndex) - occurrenceIndices.begin();

            // Find previous occurrence in circular manner
            int previousOccurrenceIndex =
                occurrenceIndices[(positionInList - 1 + occurrencesCount) % occurrencesCount];

            // Find next occurrence in circular manner
            int nextOccurrenceIndex =
                occurrenceIndices[(positionInList + 1) % occurrencesCount];

            // Direct distances (linear)
            int distanceToPrevious = abs(previousOccurrenceIndex - queryIndex);
            int distanceToNext = abs(nextOccurrenceIndex - queryIndex);

            // Since array is circular, we also consider wrap-around distances
            int circularDistanceToPrevious = arraySize - distanceToPrevious;
            int circularDistanceToNext = arraySize - distanceToNext;

            // Take the minimum of all possible distances
            int minimumDistance = min({
                distanceToPrevious,
                distanceToNext,
                circularDistanceToPrevious,
                circularDistanceToNext
            });

            answer.push_back(minimumDistance);
        }

        return answer;
    }
};

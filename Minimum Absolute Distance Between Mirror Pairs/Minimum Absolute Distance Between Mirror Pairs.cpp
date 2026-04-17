// Solution for Minimum Absolute Distance Between Mirror Pairs in CPP

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        
        // Map: stores the latest index where a "reversed value" is expected
        unordered_map<int, int> reverseIndexMap;

        int totalElements = nums.size();
        int minimumDistance = INT_MAX;

        // Lambda to reverse digits of a number
        auto getReversedNumber = [](int number) {
            string numStr = to_string(number);
            reverse(numStr.begin(), numStr.end());
            return stoi(numStr); // leading zeros automatically removed
        };

        for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {
            
            int currentValue = nums[currentIndex];

            // Check if current value matches any previously stored reversed value
            if (reverseIndexMap.count(currentValue)) {
                int previousIndex = reverseIndexMap[currentValue];

                // Update minimum distance between mirror pair
                minimumDistance = min(minimumDistance, currentIndex - previousIndex);
            }

            // Store the reversed value of current number with its index
            int reversedValue = getReversedNumber(currentValue);
            reverseIndexMap[reversedValue] = currentIndex;
        }

        // If no mirror pair found, return -1
        return (minimumDistance == INT_MAX) ? -1 : minimumDistance;
    }
};

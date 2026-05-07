// Solution for Jump Game IX in CPP

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int totalElements = nums.size();

        // maxPrefix[i] = maximum value from nums[0...i]
        vector<int> maxPrefix(totalElements);

        // minSuffix[i] = minimum value from nums[i...n-1]
        vector<int> minSuffix(totalElements);

        // Initialize boundary values
        maxPrefix[0] = nums[0];
        minSuffix[totalElements - 1] = nums[totalElements - 1];

        // Build prefix maximum array
        // Build suffix minimum array
        for (int index = 1; index < totalElements; index++) {

            maxPrefix[index] = max(maxPrefix[index - 1], nums[index]);

            minSuffix[totalElements - 1 - index] =
                min(minSuffix[totalElements - index], nums[totalElements - 1 - index]);
        }

        vector<int> maximumReachable(totalElements);

        // Last position can always reach global prefix maximum till there
        maximumReachable[totalElements - 1] = maxPrefix[totalElements - 1];

        // Process from right to left
        for (int index = totalElements - 2; index >= 0; index--) {

            // If there exists a smaller value on the right,
            // then current index can eventually connect further
            if (maxPrefix[index] > minSuffix[index + 1]) {

                // Inherit answer from right side
                maximumReachable[index] = maximumReachable[index + 1];

            } else {

                // Cannot expand further
                maximumReachable[index] = maxPrefix[index];
            }
        }

        return maximumReachable;
    }
};

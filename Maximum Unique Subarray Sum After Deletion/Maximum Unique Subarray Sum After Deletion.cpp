// Solution for Maximum Unique Subarray Sum After Deletion in CPP

class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> seen(101, -1); // Track which positive numbers have been added
        int maxSum = 0;            // To store sum of unique positive elements
        int maxNegative = INT_MIN; // Track max negative in case all are <= 0

        for (const auto& num : nums) {
            if (num <= 0) {
                // Keep track of highest negative number
                maxNegative = max(maxNegative, num);
            } else if (seen[num] == -1) {
                // Add unique positive number to sum
                maxSum += num;
                seen[num] = 1;
            }
        }

        // If no positive number was added, return the max negative
        return maxSum == 0 ? maxNegative : maxSum;
    }
};

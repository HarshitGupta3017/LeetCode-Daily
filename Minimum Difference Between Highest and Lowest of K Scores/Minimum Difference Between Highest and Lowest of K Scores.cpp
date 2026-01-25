// Solution for Minimum Difference Between Highest and Lowest of K Scores in CPP

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        // If we pick only one student, the difference is always 0
        if (k == 1) {
            return 0;
        }

        // Sort the scores so that close values come together
        sort(nums.begin(), nums.end());

        int minimumScoreDifference = INT_MAX;   // Stores the final answer
        int totalStudents = nums.size();

        // Sliding window of size k
        for (int startIndex = 0; startIndex + k - 1 < totalStudents; startIndex++) {

            // Lowest score in the current group of k students
            int lowestScore = nums[startIndex];

            // Highest score in the current group of k students
            int highestScore = nums[startIndex + k - 1];

            // Update the minimum possible difference
            minimumScoreDifference = min(minimumScoreDifference, highestScore - lowestScore);
        }

        // Return the minimum difference found
        return minimumScoreDifference;
    }
};

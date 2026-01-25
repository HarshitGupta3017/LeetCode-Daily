// Solution for Minimum Difference Between Highest and Lowest of K Scores in JAVA

class Solution {
    public int minimumDifference(int[] nums, int k) {

        // If only one student is selected, difference is always 0
        if (k == 1) {
            return 0;
        }

        // Sort the array so that close values come together
        Arrays.sort(nums);

        int minDifference = Integer.MAX_VALUE;
        int n = nums.length;

        // Sliding window of size k
        for (int start = 0; start + k - 1 < n; start++) {

            // Lowest score in current window
            int lowestScore = nums[start];

            // Highest score in current window
            int highestScore = nums[start + k - 1];

            // Update minimum difference
            minDifference = Math.min(minDifference, highestScore - lowestScore);
        }

        return minDifference;
    }
}

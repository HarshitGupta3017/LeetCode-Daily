// Solution for Minimize Maximum Pair Sum in Array in CPP

class Solution {
public:
    int minPairSum(vector<int>& nums) {

        // Sort the array so that we can pair
        // the smallest element with the largest one
        sort(nums.begin(), nums.end());

        int leftIndex = 0;                      // Pointer to the smallest element
        int rightIndex = nums.size() - 1;       // Pointer to the largest element

        int maximumPairSum = 0;                 // Stores the minimized maximum pair sum

        // Pair elements until all pairs are formed
        while (leftIndex < rightIndex) {

            // Calculate current pair sum
            int currentPairSum = nums[leftIndex] + nums[rightIndex];

            // Update the maximum pair sum encountered so far
            maximumPairSum = max(maximumPairSum, currentPairSum);

            // Move both pointers inward
            leftIndex++;
            rightIndex--;
        }

        // Return the minimized maximum pair sum
        return maximumPairSum;
    }
};

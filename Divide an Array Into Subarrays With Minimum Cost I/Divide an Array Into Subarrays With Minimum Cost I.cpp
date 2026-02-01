// Solution for Divide an Array Into Subarrays With Minimum Cost I in CPP

class Solution {
public:
    int minimumCost(vector<int>& nums) {

        /*
            Observation:
            - We must divide the array into exactly 3 contiguous subarrays.
            - The "cost" of each subarray is its first element.
            - The first subarray MUST start at index 0,
              so nums[0] is always included in the answer.
        */

        int totalCost = nums[0];  // Cost of the first subarray

        /*
            We now need to choose the starting elements
            of the 2nd and 3rd subarrays.

            Since subarrays are contiguous and disjoint:
            - Their starting indices must be somewhere after index 0.
            - To minimize total cost, we just need the
              two smallest values from nums[1 ... n-1].
        */

        int smallest = INT_MAX;        // smallest value in nums[1..]
        int secondSmallest = INT_MAX;  // second smallest value in nums[1..]

        for (int i = 1; i < nums.size(); i++) {

            /*
                Update the two smallest values seen so far.
                Classic "find 2 minimum elements" pattern.
            */
            if (nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            } 
            else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }

        /*
            Final answer:
            - cost of first subarray  -> nums[0]
            - cost of second subarray -> smallest
            - cost of third subarray  -> secondSmallest
        */
        return totalCost + smallest + secondSmallest;
    }
};

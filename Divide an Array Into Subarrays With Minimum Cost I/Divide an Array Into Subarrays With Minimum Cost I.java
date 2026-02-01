// Solution for Divide an Array Into Subarrays With Minimum Cost I in JAVA

class Solution {
    public int minimumCost(int[] nums) {

        // Cost of the first subarray (must start at index 0)
        int totalCost = nums[0];

        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;

        // Find two smallest elements in nums[1..n-1]
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            } else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }

        return totalCost + smallest + secondSmallest;
    }
}

// Solution for Find Minimum in Rotated Sorted Array II in JAVA

class Solution {
    public int findMin(int[] nums) {

        int left = 0;
        int right = nums.length - 1;

        // Store index of smallest element found so far
        int minimumIndex = 0;

        while (left <= right) {

            // Remove duplicate values from left boundary
            while (left < right && nums[left] == nums[left + 1]) {
                left++;
            }

            // Remove duplicate values from right boundary
            while (right > left && nums[right] == nums[right - 1]) {
                right--;
            }

            int middle = left + (right - left) / 2;

            // Update minimum element index if a smaller value is found
            if (nums[middle] < nums[minimumIndex]) {
                minimumIndex = middle;
            }

            // If middle element is greater than rightmost element,
            // rotation point must exist in the right half
            if (nums[middle] > nums[right]) {
                left = middle + 1;
            }

            // Otherwise, minimum lies in left half
            else {
                right = middle - 1;
            }
        }

        return nums[minimumIndex];
    }
}

// Solution for Valid Triangle Number in JAVA

class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);  // Step 1: sort the array
        int totalTriangles = 0;

        // Step 2: fix the largest side
        for (int largest = n - 1; largest >= 2; largest--) {
            int left = 0, right = largest - 1;

            // Step 3: two-pointer check
            while (left < right) {
                if (nums[left] + nums[right] > nums[largest]) {
                    totalTriangles += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return totalTriangles;
    }
}

// Solution for Number of Zero-Filled Subarrays in JAVA

class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long result = 0;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            count = (nums[i] == 0) ? count + 1 : 0;
            result += count;
        }   
        return result;
    }
}

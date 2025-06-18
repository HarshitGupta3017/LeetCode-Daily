// Solution for Divide Array Into Arrays With Max Difference in JAVA

class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        if (n % 3 != 0) return new int[0][];
        
        int[][] result = new int[n / 3][3];
        int index = 0;

        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return new int[0][];
            }
            result[index++] = new int[]{nums[i], nums[i + 1], nums[i + 2]};
        }

        return result;
    }
}

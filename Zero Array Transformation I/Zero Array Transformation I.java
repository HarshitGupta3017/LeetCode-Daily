// Solution for Zero Array Transformation I in JAVA

class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] diff = new int[n];
        for (int[] q: queries) {
            int start = q[0], end = q[1];
            int x = 1;
            diff[start] += 1;
            if (end + 1 < n) 
                diff[end + 1] -= 1; 
        }
        int[] res = new int[n];
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            res[i] = cumSum;
        }
        for (int i = 0; i < n; i++) {
            if (res[i] < nums[i])
                return false;
        }
        return true;   
    }
}

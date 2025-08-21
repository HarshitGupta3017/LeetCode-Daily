// Solution for Count Submatrices With All Ones in JAVA

class Solution {
    private int countSubarraysWithOnes(int[] arr) {
        int ones = 0, total = 0;
        for (int val : arr) {
            if (val == 0) ones = 0;
            else ones++;
            total += ones;
        }
        return total;
    }

    public int numSubmat(int[][] mat) {
        int rows = mat.length, cols = mat[0].length, total = 0;
        int[] mask = new int[cols];
        for (int i = 0; i < rows; i++) {
            Arrays.fill(mask, 1);
            for (int j = i; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    mask[k] &= mat[j][k];
                }
                total += countSubarraysWithOnes(mask);
            }
        }
        return total;
    }
}

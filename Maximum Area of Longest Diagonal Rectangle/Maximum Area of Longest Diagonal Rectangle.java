// Solution for Maximum Area of Longest Diagonal Rectangle in JAVA

class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiag = 0, maxArea = 0;
        int n = dimensions.length;
        for (int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int diag = l*l + w*w;
            int area = l * w;
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag) {
                maxArea = Math.max(maxArea, area);
            }
        }
        return maxArea;
    }
}

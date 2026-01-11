// Solution for Maximal Rectangle in JAVA

class Solution {

    /*
        Finds the index of the Next Smaller element to the Right (NSR)
        for each bar in the histogram.
        If no smaller element exists, index is set to n.
    */
    private int[] findNSR(int[] heights, int n) {
        Stack<Integer> stack = new Stack<>();
        int[] NSR = new int[n];

        stack.push(n - 1);
        NSR[n - 1] = n;

        for (int i = n - 2; i >= 0; i--) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            NSR[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }
        return NSR;
    }

    /*
        Finds the index of the Next Smaller element to the Left (NSL)
        for each bar in the histogram.
        If no smaller element exists, index is set to -1.
    */
    private int[] findNSL(int[] heights, int n) {
        Stack<Integer> stack = new Stack<>();
        int[] NSL = new int[n];

        stack.push(0);
        NSL[0] = -1;

        for (int i = 1; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            NSL[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }
        return NSL;
    }

    /*
        Computes the maximum rectangular area in a histogram.
    */
    private int findArea(int[] heights, int n) {
        int[] NSR = findNSR(heights, n);
        int[] NSL = findNSL(heights, n);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = NSR[i] - NSL[i] - 1;
            maxArea = Math.max(maxArea, height * width);
        }
        return maxArea;
    }

    /*
        Treat each row as a histogram of consecutive 1's.
    */
    public int maximalRectangle(char[][] matrix) {

        int m = matrix.length;
        int n = matrix[0].length;

        int[] heights = new int[n];

        // First row histogram
        for (int col = 0; col < n; col++) {
            heights[col] = (matrix[0][col] == '1') ? 1 : 0;
        }

        int maxArea = findArea(heights, n);

        // Remaining rows
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col]++;
                }
            }
            maxArea = Math.max(maxArea, findArea(heights, n));
        }

        return maxArea;
    }
}

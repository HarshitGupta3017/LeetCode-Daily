// Solution for Maximal Rectangle in CPP

class Solution {
public:

    /*
        Finds the index of the Next Smaller element to the Right (NSR)
        for each bar in the histogram.
        If no smaller element exists, index is set to n.
    */
    vector<int> findNSR(vector<int>& heights, int n) {
        stack<int> st;          // stores indices
        vector<int> NSR(n);

        // Last bar has no bar to its right
        st.push(n - 1);
        NSR[n - 1] = n;

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {

            // Remove all bars taller or equal to current bar
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller bar to the right
            NSR[i] = st.empty() ? n : st.top();

            // Push current index
            st.push(i);
        }
        return NSR;
    }

    /*
        Finds the index of the Next Smaller element to the Left (NSL)
        for each bar in the histogram.
        If no smaller element exists, index is set to -1.
    */
    vector<int> findNSL(vector<int>& heights, int n) {
        stack<int> st;          // stores indices
        vector<int> NSL(n);

        // First bar has no bar to its left
        st.push(0);
        NSL[0] = -1;

        // Traverse from left to right
        for (int i = 1; i < n; i++) {

            // Remove all bars taller or equal to current bar
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller bar to the left
            NSL[i] = st.empty() ? -1 : st.top();

            // Push current index
            st.push(i);
        }
        return NSL;
    }

    /*
        Computes the maximum rectangular area in a histogram
        using NSL and NSR arrays.
    */
    int findArea(vector<int>& heights, int n) {

        // Get nearest smaller elements on both sides
        vector<int> NSR = findNSR(heights, n);
        vector<int> NSL = findNSL(heights, n);

        int maxArea = 0;

        // Calculate area considering each bar as height
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = NSR[i] - NSL[i] - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }

    /*
        Treat each row as a histogram where heights represent
        consecutive 1's above the current row.
    */
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);

        // Build histogram for the first row
        for (int col = 0; col < n; col++) {
            heights[col] = (matrix[0][col] == '1') ? 1 : 0;
        }

        int maxArea = findArea(heights, n);

        // Process remaining rows
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {

                // Reset height if cell is '0'
                if (matrix[row][col] == '0') {
                    heights[col] = 0;
                }
                // Increase height if cell is '1'
                else {
                    heights[col] += 1;
                }
            }

            // Update maximum rectangle area
            maxArea = max(maxArea, findArea(heights, n));
        }

        return maxArea;
    }
};

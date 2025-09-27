// Solution for Largest Triangle Area in CPP

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();           // Number of points available
        double maxTriangleArea = 0.0;    // Store the maximum triangle area found

        // Step 1: Iterate over all possible triplets of points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    
                    // Extract coordinates of the three chosen points
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];

                    // Step 2: Compute area using Shoelace formula
                    // Formula: 0.5 * |x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)|
                    double area = 0.5 * fabs(x1 * (y2 - y3) +
                                             x2 * (y3 - y1) +
                                             x3 * (y1 - y2));

                    // Step 3: Update maximum area if this triangle is larger
                    maxTriangleArea = max(maxTriangleArea, area);
                }
            }
        }

        return maxTriangleArea;  // Return the largest triangle area found
    }
};

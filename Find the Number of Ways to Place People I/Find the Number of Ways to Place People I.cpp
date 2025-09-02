// Solution for Find the Number of Ways to Place People I in CPP

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        // Sorting points:
        //   - By increasing x
        //   - If same x, higher y first
        auto lambda = [](auto& p1, auto& p2){
            if (p1[0] == p2[0]) {
                return p1[1] > p2[1];
            }
            return p1[0] < p2[0];
        };
        sort(points.begin(), points.end(), lambda);

        for (int i = 0; i < n; i++) {
            // Consider current point as A
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            int maxY = INT_MIN;  // Keeps track of "highest y so far" among valid B points

            for (int j = i+1; j < n; j++) {
                // Candidate B
                int x2 = points[j][0];
                int y2 = points[j][1];

                // Condition 1: A must be above B
                if (y2 > y1) continue; // B is above A → not valid

                // Condition 2: No other point in between
                // We ensure this by checking `maxY`
                if (y2 > maxY) {
                    result++;    // Found a valid (A, B)
                    maxY = y2;   // Update maxY boundary
                }
            }
        }
        return result;
    }
};

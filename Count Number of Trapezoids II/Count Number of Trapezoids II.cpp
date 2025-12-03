// Solution for Count Number of Trapezoids II in CPP

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        int n = points.size();

        // Key idea:
        // 1) Every pair of points defines a line with slope + intercept
        // 2) Trapezoid exists if we pick two *parallel* lines that are not collinear
        // 3) We:
        //      - Count all unordered pairs of parallel lines   (A)
        //      - Subtract cases where the lines share midpoint and slope (same line duplicates)  (B)
        //    Answer = A - B

        unordered_map<double, vector<double>> slopeToIntercepts;
        unordered_map<string, vector<double>> midpointToSlopes;


        // ------------------------------------------------------------
        // STEP 1: Build every line slope + intercept for all point pairs
        // ------------------------------------------------------------

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                double slope, intercept;

                // Handle vertical lines
                if (dx == 0) {
                    slope = 1e18;       // special slope for vertical lines
                    intercept = x1;     // x = constant
                } 
                // Non-vertical → slope = dy/dx, intercept via rearranged formula
                else {
                    slope = (double)dy / dx;
                    intercept = (double)(y1 * dx - x1 * dy) / dx;
                }

                // midpointKey = (x1 + x2, y1 + y2) as a unique signature
                // This identifies lines that share same midpoint & slope → collinear duplicates
                string midKey = to_string(x1 + x2) + "_" + to_string(y1 + y2);

                midpointToSlopes[midKey].push_back(slope);
                slopeToIntercepts[slope].push_back(intercept);
            }
        }


        long long total = 0;

        // ------------------------------------------------------------
        // STEP 2: Count unordered pairs of *distinct, parallel lines*
        // ------------------------------------------------------------

        for (const auto& [slope, interceptList] : slopeToIntercepts) {

            if (interceptList.size() <= 1) 
                continue;

            // Count frequencies of intercepts (different positions of same slope)
            map<double, int> freqMap;
            for (double intercept : interceptList) {
                freqMap[intercept]++;
            }

            // For each bucket, accumulate combinatorially:
            // If intercepts counts are c1, c2, c3...
            // total += c1*(c2+c3...) + c2*(c3...) ...
            long long prefix = 0;
            for (const auto& [intercept, count] : freqMap) {
                total += (long long)count * prefix;
                prefix += count;
            }
        }


        // ------------------------------------------------------------
        // STEP 3: Subtract duplicate contributions from collinear lines
        //         (same midpoint and same slope → they are same line)
        // ------------------------------------------------------------

        for (const auto& [midKey, slopes] : midpointToSlopes) {

            if (slopes.size() <= 1) 
                continue;

            map<double, int> freqMap;
            for (double slope : slopes) {
                freqMap[slope]++;
            }

            long long prefix = 0;
            for (const auto& [slope, count] : freqMap) {
                total -= (long long)count * prefix;
                prefix += count;
            }
        }

        return (int)total;
    }
};

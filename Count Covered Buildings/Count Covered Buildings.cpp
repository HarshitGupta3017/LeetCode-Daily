// Solution for Count Covered Buildings in CPP

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // Maps each row (y) → {minX, maxX} of buildings in that row
        unordered_map<int, pair<int, int>> rowToMinMaxX;

        // Maps each column (x) → {minY, maxY} of buildings in that column
        unordered_map<int, pair<int, int>> colToMinMaxY;

        // ----------------------------------------------------------
        // STEP 1: Precompute row and column boundaries.
        // We track the smallest/biggest x in each row,
        // and the smallest/biggest y in each column.
        // ----------------------------------------------------------
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            // Initialize row if needed
            if (!rowToMinMaxX.count(y)) {
                rowToMinMaxX[y] = {INT_MAX, INT_MIN};
            }

            // Initialize column if needed
            if (!colToMinMaxY.count(x)) {
                colToMinMaxY[x] = {INT_MAX, INT_MIN};
            }

            // Update row boundaries for y
            rowToMinMaxX[y].first  = min(rowToMinMaxX[y].first,  x);
            rowToMinMaxX[y].second = max(rowToMinMaxX[y].second, x);

            // Update column boundaries for x
            colToMinMaxY[x].first  = min(colToMinMaxY[x].first,  y);
            colToMinMaxY[x].second = max(colToMinMaxY[x].second, y);
        }

        // ----------------------------------------------------------
        // STEP 2: Count buildings that are strictly between min/max
        // in both their row and column.
        // ----------------------------------------------------------
        int coveredCount = 0;

        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            auto& rowLimits = rowToMinMaxX[y];   // {minX, maxX}
            auto& colLimits = colToMinMaxY[x];   // {minY, maxY}

            bool hasLeft   = rowLimits.first  < x;
            bool hasRight  = x < rowLimits.second;
            bool hasBelow  = colLimits.first  < y;
            bool hasAbove  = y < colLimits.second;

            // Covered if all four directional buildings exist
            if (hasLeft && hasRight && hasBelow && hasAbove) {
                coveredCount++;
            }
        }

        return coveredCount;
    }
};

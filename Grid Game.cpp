class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowRemSum = 0;
        long long minR1 = LONG_LONG_MAX;
        for (int col = 0; col < grid[0].size(); col++) {
            firstRowRemSum -= grid[0][col];
            long long maxR2 = max(firstRowRemSum, secondRowRemSum);
            secondRowRemSum += grid[1][col];
            minR1 = min(minR1, maxR2);
        }
        return minR1;
    }
};

// Solution for Shift 2D Grid in CPP

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalCells = rows * cols;

        // Shifting by a full cycle returns the grid unchanged.
        k %= totalCells;
        if (k == 0) return grid;

        // We treat the 2D grid as a flat 1D array of length totalCells,
        // mapping flat index i → grid[i / cols][i % cols].
        // A right-shift by k on a flat array is equivalent to a rotation,
        // which can be done in-place using the classic three-reversal trick:
        //   reverse entire array → reverse first k → reverse remaining (n-k)
        auto reverseSegment = [&](int lo, int hi) {
            while (lo < hi) {
                swap(grid[lo / cols][lo % cols], grid[hi / cols][hi % cols]);
                lo++;
                hi--;
            }
        };

        // After reversing the whole array, the last k elements (which should
        // end up at the front after a right-shift) are now at the front but
        // in reverse order. The two sub-reversals fix their internal order.
        reverseSegment(0, totalCells - 1);  // reverse entire flat array
        reverseSegment(0, k - 1);           // restore order of the new front block
        reverseSegment(k, totalCells - 1);  // restore order of the new back block

        return grid;
    }
};

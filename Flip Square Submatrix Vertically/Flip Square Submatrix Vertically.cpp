// Solution for Flip Square Submatrix Vertically in CPP

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        /*
            Define boundaries of the k x k submatrix
        */
        int topRow = x;
        int bottomRow = x + k - 1;
        int leftCol = y;
        int rightCol = y + k - 1;

        /*
            We only need to process half rows
            because each swap fixes two rows
        */
        while (topRow < bottomRow) {

            /*
                Swap entire rows within column range [y, y+k-1]
            */
            for (int col = leftCol; col <= rightCol; col++) {
                swap(grid[topRow][col], grid[bottomRow][col]);
            }

            /*
                Move pointers inward
            */
            topRow++;
            bottomRow--;
        }

        return grid;
    }
};

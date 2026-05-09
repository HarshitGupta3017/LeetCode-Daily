// Solution for Cyclically Rotating a Grid in CPP

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Number of concentric layers in matrix
        int totalLayers = min(rows, cols) / 2;

        // Process each layer independently
        for (int layer = 0; layer < totalLayers; layer++) {

            int topRow = layer;
            int leftCol = layer;

            int bottomRow = rows - layer - 1;
            int rightCol = cols - layer - 1;

            vector<int> layerElements;

            // -----------------------------------
            // Extract current layer elements
            // in traversal order
            // -----------------------------------

            // Top row (left -> right)
            for (int col = leftCol; col < rightCol; col++) {
                layerElements.push_back(grid[topRow][col]);
            }

            // Right column (top -> bottom)
            for (int row = topRow; row < bottomRow; row++) {
                layerElements.push_back(grid[row][rightCol]);
            }

            // Bottom row (right -> left)
            for (int col = rightCol; col > leftCol; col--) {
                layerElements.push_back(grid[bottomRow][col]);
            }

            // Left column (bottom -> top)
            for (int row = bottomRow; row > topRow; row--) {
                layerElements.push_back(grid[row][leftCol]);
            }

            int layerSize = layerElements.size();

            // Effective rotation needed
            int rotationSteps = k % layerSize;

            // Counter-clockwise cyclic rotation
            rotate(layerElements.begin(),
                   layerElements.begin() + rotationSteps,
                   layerElements.end());

            int currentIndex = 0;

            // -----------------------------------
            // Fill rotated values back into grid
            // -----------------------------------

            // Top row
            for (int col = leftCol; col < rightCol; col++) {
                grid[topRow][col] = layerElements[currentIndex++];
            }

            // Right column
            for (int row = topRow; row < bottomRow; row++) {
                grid[row][rightCol] = layerElements[currentIndex++];
            }

            // Bottom row
            for (int col = rightCol; col > leftCol; col--) {
                grid[bottomRow][col] = layerElements[currentIndex++];
            }

            // Left column
            for (int row = bottomRow; row > topRow; row--) {
                grid[row][leftCol] = layerElements[currentIndex++];
            }
        }

        return grid;
    }
};

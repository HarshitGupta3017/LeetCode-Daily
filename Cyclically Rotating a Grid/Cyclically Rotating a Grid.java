// Solution for Cyclically Rotating a Grid in JAVA

class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {

        int rows = grid.length;
        int cols = grid[0].length;

        // Number of layers
        int totalLayers = Math.min(rows, cols) / 2;

        for (int layer = 0; layer < totalLayers; layer++) {

            int topRow = layer;
            int leftCol = layer;

            int bottomRow = rows - layer - 1;
            int rightCol = cols - layer - 1;

            List<Integer> layerElements = new ArrayList<>();

            // Top row
            for (int col = leftCol; col < rightCol; col++) {
                layerElements.add(grid[topRow][col]);
            }

            // Right column
            for (int row = topRow; row < bottomRow; row++) {
                layerElements.add(grid[row][rightCol]);
            }

            // Bottom row
            for (int col = rightCol; col > leftCol; col--) {
                layerElements.add(grid[bottomRow][col]);
            }

            // Left column
            for (int row = bottomRow; row > topRow; row--) {
                layerElements.add(grid[row][leftCol]);
            }

            int layerSize = layerElements.size();
            int rotationSteps = k % layerSize;

            // Rotate counter-clockwise
            Collections.rotate(layerElements, -rotationSteps);

            int index = 0;

            // Fill back

            // Top row
            for (int col = leftCol; col < rightCol; col++) {
                grid[topRow][col] = layerElements.get(index++);
            }

            // Right column
            for (int row = topRow; row < bottomRow; row++) {
                grid[row][rightCol] = layerElements.get(index++);
            }

            // Bottom row
            for (int col = rightCol; col > leftCol; col--) {
                grid[bottomRow][col] = layerElements.get(index++);
            }

            // Left column
            for (int row = bottomRow; row > topRow; row--) {
                grid[row][leftCol] = layerElements.get(index++);
            }
        }

        return grid;
    }
}

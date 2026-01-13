// Solution for Separate Squares I in JAVA

class Solution {

    // Check if area below midY is at least half of total area
    private boolean isBottomAreaEnough(int[][] squares, double midY, double totalArea) {
        double bottomArea = 0.0;

        for (int[] square : squares) {
            double y = square[1];
            double l = square[2];

            double topY = y + l;
            double bottomY = y;

            // Entire square is below midY
            if (midY > topY) {
                bottomArea += l * l;
            }
            // Partial square below midY
            else if (midY > bottomY) {
                bottomArea += (midY - y) * l;
            }
        }

        return bottomArea >= totalArea / 2.0;
    }

    public double separateSquares(int[][] squares) {
        double low = Double.MAX_VALUE;
        double high = Double.MIN_VALUE;
        double totalArea = 0.0;

        // Compute total area and search boundaries
        for (int[] square : squares) {
            double y = square[1];
            double l = square[2];

            totalArea += l * l;
            low = Math.min(low, y);
            high = Math.max(high, y + l);
        }

        double resultY = 0.0;

        // Binary search with precision tolerance
        while (high - low > 1e-5) {
            double midY = low + (high - low) / 2.0;

            if (isBottomAreaEnough(squares, midY, totalArea)) {
                resultY = midY;
                high = midY;
            } else {
                low = midY;
            }
        }

        return resultY;
    }
}

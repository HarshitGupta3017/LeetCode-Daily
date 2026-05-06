// Solution for Rotating the Box in JAVA

class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {

        int originalRows = boxGrid.length;
        int originalCols = boxGrid[0].length;

        // Create rotated matrix
        char[][] rotatedBox = new char[originalCols][originalRows];

        // STEP 1: Rotate the matrix
        for (int row = 0; row < originalRows; row++) {
            for (int col = 0; col < originalCols; col++) {
                rotatedBox[col][originalRows - row - 1] = boxGrid[row][col];
            }
        }

        // STEP 2: Apply gravity
        for (int col = 0; col < originalRows; col++) {

            int emptyRowPointer = originalCols - 1;

            for (int row = originalCols - 1; row >= 0; row--) {

                if (rotatedBox[row][col] == '*') {
                    emptyRowPointer = row - 1;
                } 
                else if (rotatedBox[row][col] == '#') {
                    rotatedBox[row][col] = '.';
                    rotatedBox[emptyRowPointer][col] = '#';
                    emptyRowPointer--;
                }
            }
        }

        return rotatedBox;
    }
}

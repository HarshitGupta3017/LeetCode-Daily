// Solution for Length of Longest V-Shaped Diagonal Segment in JAVA

class Solution {
    int[][][] directions = {{{1,1}}, {{1,-1}}, {{-1,-1}}, {{-1,1}}};
    int[][][][] t;

    int dfs(int row, int col, int dir, int canTurn, int expectedVal, int[][] grid, int rows, int cols) {
        int newRow = row + directions[dir][0][0];
        int newCol = col + directions[dir][0][1];
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != expectedVal) 
            return 0;
        if (t[newRow][newCol][dir][canTurn] != -1) 
            return t[newRow][newCol][dir][canTurn];
        int continueStraight = 1 + dfs(newRow, newCol, dir, canTurn, expectedVal == 2 ? 0 : 2, grid, rows, cols);
        int longestPath = continueStraight;
        if (canTurn == 1) {
            int afterTurn = 1 + dfs(newRow, newCol, (dir + 1) % 4, 0, expectedVal == 2 ? 0 : 2, grid, rows, cols);
            longestPath = Math.max(longestPath, afterTurn);
        }
        return t[newRow][newCol][dir][canTurn] = longestPath;
    }

    public int lenOfVDiagonal(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        t = new int[rows][cols][4][2];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                for (int d = 0; d < 4; d++)
                    for (int k = 0; k < 2; k++)
                        t[i][j][d][k] = -1;
        int maxLength = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        maxLength = Math.max(maxLength, 1 + dfs(r, c, dir, 1, 2, grid, rows, cols));
                    }
                }
            }
        }
        return maxLength;
    }
}

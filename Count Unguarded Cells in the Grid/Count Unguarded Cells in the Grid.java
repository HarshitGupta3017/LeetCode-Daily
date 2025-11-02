// Solution for Count Unguarded Cells in the Grid in JAVA

class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n]; 
        // 0 → empty, 1 → guarded, 2 → blocked (guard or wall)

        // Mark guards and walls as blocked
        for (int[] g : guards) grid[g[0]][g[1]] = 2;
        for (int[] w : walls) grid[w[0]][w[1]] = 2;

        int[][] dirs = {{1,0}, {0,-1}, {-1,0}, {0,1}};

        // Simulate guard vision
        for (int[] g : guards) {
            for (int[] d : dirs) {
                int r = g[0] + d[0], c = g[1] + d[1];
                while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 2) {
                    grid[r][c] = 1;
                    r += d[0];
                    c += d[1];
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) count++;

        return count;
    }
}

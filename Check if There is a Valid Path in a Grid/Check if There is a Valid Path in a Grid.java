// Solution for Check if There is a Valid Path in a Grid in JAVA

class Solution {

    // Mapping each street type to its possible movement directions
    private static final Map<Integer, int[][]> streetDirections = new HashMap<>();

    static {
        streetDirections.put(1, new int[][]{{0, -1}, {0, 1}});
        streetDirections.put(2, new int[][]{{-1, 0}, {1, 0}});
        streetDirections.put(3, new int[][]{{0, -1}, {1, 0}});
        streetDirections.put(4, new int[][]{{0, 1}, {1, 0}});
        streetDirections.put(5, new int[][]{{0, -1}, {-1, 0}});
        streetDirections.put(6, new int[][]{{-1, 0}, {0, 1}});
    }

    private boolean dfs(int[][] grid, int r, int c, boolean[][] visited) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Reached destination
        if (r == rows - 1 && c == cols - 1) return true;

        visited[r][c] = true;

        for (int[] dir : streetDirections.get(grid[r][c])) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visited[nr][nc])
                continue;

            // Check reverse connection
            for (int[] rev : streetDirections.get(grid[nr][nc])) {
                if (nr + rev[0] == r && nc + rev[1] == c) {
                    if (dfs(grid, nr, nc, visited))
                        return true;
                }
            }
        }

        return false;
    }

    public boolean hasValidPath(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        return dfs(grid, 0, 0, visited);
    }
}

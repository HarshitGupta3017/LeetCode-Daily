// Solution for Pacific Atlantic Water Flow in JAVA

class Solution {
    int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        boolean[][] pac = new boolean[m][n], atl = new boolean[m][n];
        
        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, n-1);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j);
            dfs(heights, atl, m-1, j);
        }
        
        List<List<Integer>> res = new ArrayList<>();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.add(Arrays.asList(i,j));
                }
            }
        }
        return res;
    }
    
    void dfs(int[][] h, boolean[][] vis, int i, int j) {
        int m = h.length, n = h[0].length;
        vis[i][j] = true;
        for (int[] dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && h[ni][nj]>=h[i][j]) {
                dfs(h, vis, ni, nj);
            }
        }
    }
}

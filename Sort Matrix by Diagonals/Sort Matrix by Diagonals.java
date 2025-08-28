// Solution for Sort Matrix by Diagonals in JAVA

class Solution {
    public int[][] sortMatrix(int[][] grid) {
        Map<Integer, List<Integer>> bottomLeftDiags = new HashMap<>();
        Map<Integer, List<Integer>> topRightDiags = new HashMap<>();
        int n = grid.length;
        
        // Group elements by diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    bottomLeftDiags.computeIfAbsent(i - j, k -> new ArrayList<>()).add(grid[i][j]);
                } else {
                    topRightDiags.computeIfAbsent(i - j, k -> new ArrayList<>()).add(grid[i][j]);
                }
            }
        }

        // Sort diagonals for bottom-left triangle (non-increasing order)
        for (List<Integer> list : bottomLeftDiags.values()) {
            Collections.sort(list);
        }

        // Sort diagonals for top-right triangle (non-decreasing order)
        for (List<Integer> list : topRightDiags.values()) {
            Collections.sort(list, Collections.reverseOrder());
        }

        // Rebuild the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    grid[i][j] = bottomLeftDiags.get(i - j).remove(bottomLeftDiags.get(i - j).size() - 1);
                } else {
                    grid[i][j] = topRightDiags.get(i - j).remove(topRightDiags.get(i - j).size() - 1);
                }
            }
        }

        return grid;
    }
}

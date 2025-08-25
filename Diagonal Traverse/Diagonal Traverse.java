// Solution for Diagonal Traverse in JAVA

class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        int rows = mat.length;
        int cols = mat[0].length;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int key = i + j;
                mp.computeIfAbsent(key, k -> new ArrayList<>()).add(mat[i][j]);
            }
        }

        int[] result = new int[rows * cols];
        int idx = 0;
        boolean flip = true;

        // keys should be processed in increasing order
        for (int key = 0; key < rows + cols - 1; key++) {
            List<Integer> diag = mp.get(key);
            if (flip) { 
                Collections.reverse(diag); 
            }
            for (int num: diag) {
                result[idx++] = num;
            }
            flip = !flip;
        }
        return result;
    }
}

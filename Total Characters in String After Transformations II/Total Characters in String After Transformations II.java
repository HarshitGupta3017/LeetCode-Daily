// Solution for Total Characters in String After Transformations II in JAVA

class Solution {
    static final int MOD = 1_000_000_007;
    static final int SIZE = 26;

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        // Step 1: Initial frequency vector
        int[] freq = new int[SIZE];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Step 2: Build transformation matrix T
        int[][] T = new int[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int add = 1; add <= nums.get(i); add++) {
                T[(i + add) % SIZE][i]++;
            }
        }

        // Step 3: Compute T^t
        int[][] result = matrixExponentiation(T, t);

        // Step 4: Multiply result * freq
        int[] finalFreq = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                finalFreq[i] = (int) ((finalFreq[i] + 1L * result[i][j] * freq[j]) % MOD);
            }
        }

        // Step 5: Sum final frequencies
        int ans = 0;
        for (int val : finalFreq) {
            ans = (ans + val) % MOD;
        }

        return ans;
    }

    private int[][] matrixExponentiation(int[][] base, int exponent) {
        int[][] identity = new int[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            identity[i][i] = 1;
        }

        if (exponent == 0) return identity;

        int[][] half = matrixExponentiation(base, exponent / 2);
        int[][] result = matrixMultiplication(half, half);

        if (exponent % 2 == 1) {
            result = matrixMultiplication(result, base);
        }

        return result;
    }

    private int[][] matrixMultiplication(int[][] A, int[][] B) {
        int[][] C = new int[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    C[i][j] = (int) ((C[i][j] + 1L * A[i][k] * B[k][j]) % MOD);
                }
            }
        }
        return C;
    }
}

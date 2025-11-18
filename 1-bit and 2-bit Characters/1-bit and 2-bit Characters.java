// Solution for 1-bit and 2-bit Characters in JAVA

class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        int trailingOnes = 0;   // Counts consecutive 1's before the final 0

        // 🔹 Count how many continuous '1's appear just before the last bit
        //    We start from n-2 because last bit is guaranteed to be 0.
        for (int i = n - 2; i >= 0 && bits[i] == 1; i--) {
            trailingOnes++;
        }

        // 🔹 If the number of trailing 1's is EVEN → last bit is single '0'
        //    If ODD → the last '0' was part of a two-bit character (10 or 11)
        return (trailingOnes % 2 == 0);
    }
}

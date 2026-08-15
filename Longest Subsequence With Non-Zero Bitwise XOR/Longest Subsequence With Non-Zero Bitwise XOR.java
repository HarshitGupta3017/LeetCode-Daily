// Solution for Longest Subsequence With Non-Zero Bitwise XOR in JAVA

class Solution {
    public int longestSubsequence(int[] nums) {
        int xor = 0;
        boolean allZero = true;

        for (int x : nums) {
            xor ^= x;
            if (x != 0) allZero = false;
        }

        if (allZero) return 0;
        return xor != 0 ? nums.length : nums.length - 1;
    }
}

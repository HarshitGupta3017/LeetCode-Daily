// Solution for Number of Substrings With Only 1s in JAVA

class Solution {

    private static final int MOD = 1000000007;

    public int numSub(String s) {

        long totalSubstrings = 0;
        long consecutiveOnes = 0;

        for (char ch : s.toCharArray()) {

            if (ch == '1') {
                consecutiveOnes++;
                totalSubstrings = (totalSubstrings + consecutiveOnes) % MOD;
            } else {
                consecutiveOnes = 0;
            }
        }

        return (int) totalSubstrings;
    }
}

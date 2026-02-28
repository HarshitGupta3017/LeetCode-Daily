// Solution for Concatenation of Consecutive Binary Numbers in JAVA

class Solution {
    public int concatenatedBinary(int n) {

        long finalNumber = 0;
        final int MOD = 1_000_000_007;

        for (int currentNumber = 1; currentNumber <= n; currentNumber++) {

            // number of bits required to represent currentNumber
            int numberOfBits = (int)(Math.log(currentNumber) / Math.log(2)) + 1;

            finalNumber = ((finalNumber << numberOfBits) % MOD + currentNumber) % MOD;
        }

        return (int) finalNumber;
    }
}

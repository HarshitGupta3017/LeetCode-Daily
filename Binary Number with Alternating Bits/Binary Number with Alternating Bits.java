// Solution for Binary Number with Alternating Bits in JAVA

class Solution {
    public boolean hasAlternatingBits(int n) {
        int xorResult = n ^ (n >> 1);
        return (xorResult & (xorResult + 1)) == 0;
    }
}

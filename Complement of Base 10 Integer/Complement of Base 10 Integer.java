// Solution for Complement of Base 10 Integer in JAVA

class Solution {
    public int bitwiseComplement(int n) {
        return n == 0 ? 1 : n ^ ((1 << ((int)(Math.log(n) / Math.log(2)) + 1)) - 1);
    }
}

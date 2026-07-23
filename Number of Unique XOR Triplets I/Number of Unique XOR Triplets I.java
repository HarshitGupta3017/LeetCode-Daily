// Solution for Number of Unique XOR Triplets I in JAVA

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        if (n <= 2) return n;
        int p = 1;
        while (p <= n) p <<= 1;
        return p;
    }
}

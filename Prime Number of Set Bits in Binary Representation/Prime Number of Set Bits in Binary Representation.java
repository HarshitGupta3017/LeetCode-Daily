// Solution for Prime Number of Set Bits in Binary Representation in JAVA

class Solution {
    public int countPrimeSetBits(int left, int right) {

        // Prime numbers <= 20
        Set<Integer> primeSetBits = new HashSet<>(
                Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19)
        );

        int count = 0;

        for (int num = left; num <= right; num++) {

            // Count set bits
            int setBits = Integer.bitCount(num);

            if (primeSetBits.contains(setBits)) {
                count++;
            }
        }

        return count;
    }
}

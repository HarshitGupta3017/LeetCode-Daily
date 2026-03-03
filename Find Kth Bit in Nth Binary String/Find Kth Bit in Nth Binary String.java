// Solution for Find Kth Bit in Nth Binary String in JAVA

class Solution {
    public char findKthBit(int n, int k) {

        // Base case: S1 = "0"
        if (n == 1) {
            return '0';
        }

        int lengthOfCurrentString = (1 << n) - 1;
        int middleIndex = 1 << (n - 1);

        // Case 1: Middle element
        if (k == middleIndex) {
            return '1';
        }

        // Case 2: Left half
        if (k < middleIndex) {
            return findKthBit(n - 1, k);
        }

        // Case 3: Right half
        int mirrorIndex = lengthOfCurrentString - k + 1;

        char mirroredBit = findKthBit(n - 1, mirrorIndex);

        // Invert bit
        return (mirroredBit == '0') ? '1' : '0';
    }
}

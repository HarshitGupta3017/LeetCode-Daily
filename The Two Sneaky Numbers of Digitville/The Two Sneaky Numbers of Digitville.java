// Solution for The Two Sneaky Numbers of Digitville in JAVA

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int originalSize = nums.length - 2;

        int xorAllElements = 0;
        for (int val : nums)
            xorAllElements ^= val;

        for (int num = 0; num < originalSize; num++)
            xorAllElements ^= num;

        // Find rightmost set bit
        int bitMask = xorAllElements & -xorAllElements;

        int group1Xor = 0, group2Xor = 0;

        for (int val : nums) {
            if ((val & bitMask) != 0) group1Xor ^= val;
            else group2Xor ^= val;
        }

        for (int num = 0; num < originalSize; num++) {
            if ((num & bitMask) != 0) group1Xor ^= num;
            else group2Xor ^= num;
        }

        return new int[]{group1Xor, group2Xor};
    }
}

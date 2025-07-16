// Solution for Find the Maximum Length of Valid Subsequence I in JAVA

class Solution {
    public int maximumLength(int[] nums) {
        int evenCount = 0;
        int oddCount = 0;
        int maxAlternatingLength = 1;
        int previousParity = nums[0] % 2;

        if (previousParity == 0) evenCount++;
        else oddCount++;

        for (int i = 1; i < nums.length; i++) {
            int currentParity = nums[i] % 2;

            if (currentParity != previousParity) {
                maxAlternatingLength++;
                previousParity = currentParity;
            }

            if (currentParity == 0) evenCount++;
            else oddCount++;
        }

        return Math.max(Math.max(evenCount, oddCount), maxAlternatingLength);
    }
}

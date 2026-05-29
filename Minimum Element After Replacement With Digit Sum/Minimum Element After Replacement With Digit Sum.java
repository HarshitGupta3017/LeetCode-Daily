// Solution for Minimum Element After Replacement With Digit Sum in JAVA

class Solution {
    public int minElement(int[] nums) {

        int minimumValue = 37;

        for (int number : nums) {

            int digitSum = 0;

            while (number > 0) {
                digitSum += number % 10;
                number /= 10;
            }

            minimumValue = Math.min(minimumValue, digitSum);
        }

        return minimumValue;
    }
}

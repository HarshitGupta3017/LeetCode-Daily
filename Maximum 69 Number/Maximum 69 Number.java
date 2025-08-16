// Solution for Maximum 69 Number in JAVA

class Solution {
    public int maximum69Number(int num) {
        int tempNum = num;
        int digitPosition = 0;
        int leftmostSixPosition = -1;

        while (tempNum > 0) {
            int currentDigit = tempNum % 10;
            if (currentDigit == 6) {
                leftmostSixPosition = digitPosition;
            }
            tempNum /= 10;
            digitPosition++;
        }

        return (leftmostSixPosition == -1) 
            ? num 
            : num + 3 * (int)Math.pow(10, leftmostSixPosition);
    }
}

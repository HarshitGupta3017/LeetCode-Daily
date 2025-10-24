// Solution for Next Greater Numerically Balanced Number in JAVA

class Solution {
    int[] remainingCount = {0,1,2,3,4,5,6,7,8,9};

    private int backtrack(int n, int current, int digitsLeft) {
        if (digitsLeft == 0) {
            for (int digit = 1; digit <= 9; digit++) {
                if (remainingCount[digit] != 0 && remainingCount[digit] != digit)
                    return 0;
            }
            return current > n ? current : 0;
        }

        int result = 0;
        for (int digit = 1; digit <= 9; digit++) {
            if (remainingCount[digit] > 0 && remainingCount[digit] <= digitsLeft) {
                remainingCount[digit]--;
                result = backtrack(n, current * 10 + digit, digitsLeft - 1);
                remainingCount[digit]++;
                if (result != 0) break;
            }
        }
        return result;
    }

    public int nextBeautifulNumber(int n) {
        int numLength = String.valueOf(n).length();
        int result = backtrack(n, 0, numLength);
        if (result == 0) result = backtrack(n, 0, numLength + 1);
        return result;
    }
}

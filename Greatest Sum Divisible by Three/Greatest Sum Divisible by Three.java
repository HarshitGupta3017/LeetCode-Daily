// Solution for Greatest Sum Divisible by Three in JAVA

class Solution {
    public int maxSumDivThree(int[] nums) {

        long totalSum = 0;

        long rem1_min1 = Long.MAX_VALUE;  // smallest remainder-1 number
        long rem1_min2 = Long.MAX_VALUE;  // second smallest

        long rem2_min1 = Long.MAX_VALUE;  // smallest remainder-2 number
        long rem2_min2 = Long.MAX_VALUE;  // second smallest

        // Step 1: Compute total sum + track smallest removal candidates
        for (int num : nums) {
            totalSum += num;
            int rem = num % 3;

            if (rem == 1) {
                if (num < rem1_min1) {
                    rem1_min2 = rem1_min1;
                    rem1_min1 = num;
                } else if (num < rem1_min2) {
                    rem1_min2 = num;
                }
            } 
            else if (rem == 2) {
                if (num < rem2_min1) {
                    rem2_min2 = rem2_min1;
                    rem2_min1 = num;
                } else if (num < rem2_min2) {
                    rem2_min2 = num;
                }
            }
        }

        // Step 2: Already divisible?
        if (totalSum % 3 == 0)
            return (int) totalSum;

        long bestRemoval = Long.MAX_VALUE;

        // Step 3: sum % 3 == 1
        if (totalSum % 3 == 1) {
            bestRemoval = Math.min(bestRemoval, rem1_min1);
            if (rem2_min2 != Long.MAX_VALUE)
                bestRemoval = Math.min(bestRemoval, rem2_min1 + rem2_min2);
        } 
        // Step 4: sum % 3 == 2
        else {
            bestRemoval = Math.min(bestRemoval, rem2_min1);
            if (rem1_min2 != Long.MAX_VALUE)
                bestRemoval = Math.min(bestRemoval, rem1_min1 + rem1_min2);
        }

        return (int) (totalSum - bestRemoval);
    }
}

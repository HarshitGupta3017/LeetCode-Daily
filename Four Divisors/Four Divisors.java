// Solution for Four Divisors in JAVA

class Solution {

    // Returns sum of divisors if num has exactly 4 divisors, else returns 0
    private int getFourDivisorSum(int num) {
        int divisorCount = 0;
        int divisorSum = 0;

        // Iterate only up to sqrt(num) to find divisor pairs
        for (int factor = 1; factor * factor <= num; factor++) {
            if (num % factor == 0) {
                int pairedFactor = num / factor;

                // Perfect square divisor
                if (factor == pairedFactor) {
                    divisorCount += 1;
                    divisorSum += factor;
                }
                // Distinct divisor pair
                else {
                    divisorCount += 2;
                    divisorSum += factor + pairedFactor;
                }
            }

            // Early exit if more than 4 divisors
            if (divisorCount > 4) {
                return 0;
            }
        }

        // Valid only if exactly 4 divisors
        return (divisorCount == 4) ? divisorSum : 0;
    }

    public int sumFourDivisors(int[] nums) {
        int totalSum = 0;

        // Process each number independently
        for (int num : nums) {
            totalSum += getFourDivisorSum(num);
        }

        return totalSum;
    }
}

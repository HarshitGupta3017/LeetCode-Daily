// Solution for Four Divisors in CPP

class Solution {
public:

    // Returns sum of divisors if `num` has exactly 4 divisors, else returns 0
    int getFourDivisorSum(int num) {
        int divisorCount = 0;
        int divisorSum = 0;

        // Iterate only up to sqrt(num) to find divisor pairs
        for (int factor = 1; factor * factor <= num; factor++) {
            if (num % factor == 0) {
                int pairedFactor = num / factor;

                // If both divisors are same (perfect square)
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

            // Early exit if divisors exceed 4
            if (divisorCount > 4) {
                return 0;
            }
        }

        // Valid only if exactly 4 divisors
        return (divisorCount == 4) ? divisorSum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        // Check each number independently
        for (int num : nums) {
            totalSum += getFourDivisorSum(num);
        }

        return totalSum;
    }
};

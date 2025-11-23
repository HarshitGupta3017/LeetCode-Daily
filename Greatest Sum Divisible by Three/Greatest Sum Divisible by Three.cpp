// Solution for Greatest Sum Divisible by Three in CPP

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        long long totalSum = 0;

        // Track the two smallest numbers with remainder 1 when divided by 3
        long long rem1_min1 = LLONG_MAX;   // smallest remainder-1 number
        long long rem1_min2 = LLONG_MAX;   // second smallest remainder-1 number

        // Track the two smallest numbers with remainder 2 when divided by 3
        long long rem2_min1 = LLONG_MAX;   // smallest remainder-2 number
        long long rem2_min2 = LLONG_MAX;   // second smallest remainder-2 number

        // Step 1: Compute total sum and record smallest candidates for removals
        for (const int num : nums) {
            totalSum += num;
            int rem = num % 3;

            if (rem == 1) {
                // Update two smallest remainder-1 values
                if (num < rem1_min1) {
                    rem1_min2 = rem1_min1;
                    rem1_min1 = num;
                } else if (num < rem1_min2) {
                    rem1_min2 = num;
                }
            } 
            else if (rem == 2) {
                // Update two smallest remainder-2 values
                if (num < rem2_min1) {
                    rem2_min2 = rem2_min1;
                    rem2_min1 = num;
                } else if (num < rem2_min2) {
                    rem2_min2 = num;
                }
            }
        }

        // Step 2: If already divisible by 3 → best possible sum
        if (totalSum % 3 == 0)
            return totalSum;

        long long bestRemoval = LLONG_MAX;

        // Step 3: If sum % 3 == 1 → remove:
        //   ✔ one smallest remainder-1 number OR
        //   ✔ two smallest remainder-2 numbers
        if (totalSum % 3 == 1) {
            bestRemoval = min(bestRemoval, rem1_min1);   // remove one rem1
            if (rem2_min2 != LLONG_MAX) {                // remove two rem2
                bestRemoval = min(bestRemoval, rem2_min1 + rem2_min2);
            }
        }
        // Step 4: If sum % 3 == 2 → remove:
        //   ✔ one smallest remainder-2 number OR
        //   ✔ two smallest remainder-1 numbers
        else {
            bestRemoval = min(bestRemoval, rem2_min1);   // remove one rem2
            if (rem1_min2 != LLONG_MAX) {                // remove two rem1
                bestRemoval = min(bestRemoval, rem1_min1 + rem1_min2);
            }
        }

        // Step 5: Max divisible sum = totalSum - minimal removal cost
        return totalSum - bestRemoval;
    }
};

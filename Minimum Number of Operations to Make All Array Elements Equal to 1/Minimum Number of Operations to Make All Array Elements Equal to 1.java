// Solution for Minimum Number of Operations to Make All Array Elements Equal to 1 in JAVA

class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;

        // Step 1️⃣: Compute the GCD of the entire array
        // If the overall GCD > 1, it's impossible to make any element 1
        // because gcd operations never introduce new prime factors.
        int arrayGCD = nums[0];
        for (int num : nums) {
            arrayGCD = gcd(arrayGCD, num);
        }
        if (arrayGCD > 1) return -1;  // Impossible case

        // Step 2️⃣: If the array already contains 1s
        // Each existing 1 can help turn its neighbor into 1 with one operation.
        // So we need (n - number_of_ones) operations to make all elements 1.
        int onesCount = 0;
        for (int num : nums) {
            if (num == 1) onesCount++;
        }
        if (onesCount > 0) return n - onesCount;

        // Step 3️⃣: Find the smallest subarray whose GCD equals 1
        // This tells us the shortest "chain" we need to combine to create a single 1.
        int minSubarrayLength = n + 1;  // Initialize with large number

        for (int start = 0; start < n; start++) {
            int currentGCD = nums[start];

            for (int end = start; end < n; end++) {
                currentGCD = gcd(currentGCD, nums[end]);

                // Once we find a subarray with GCD == 1, record its length
                if (currentGCD == 1) {
                    minSubarrayLength = Math.min(minSubarrayLength, end - start + 1);
                    break; // No need to extend further; GCD can’t get smaller than 1
                }
            }
        }

        // Step 4️⃣: Calculate total operations
        // (minSubarrayLength - 1): operations needed to turn that subarray into a single 1
        // (n - 1): operations needed to spread that 1 across the entire array
        //
        // Example: nums = [6,10,15]
        //   - Smallest subarray with gcd=1 is [6,10,15] (length = 3)
        //   - Takes (3 - 1) = 2 ops to make one '1'
        //   - Then (3 - 1) = 2 ops to spread that 1 → total 4
        return (minSubarrayLength - 1) + (n - 1);
    }

    // Helper function to compute gcd of two numbers
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}

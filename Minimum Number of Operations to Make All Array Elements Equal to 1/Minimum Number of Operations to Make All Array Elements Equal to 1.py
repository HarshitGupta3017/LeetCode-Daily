# Solution for Minimum Number of Operations to Make All Array Elements Equal to 1 in PY

class Solution:
    def minOperations(self, nums):
        n = len(nums)

        # Step 1️⃣: Compute the GCD of the entire array
        # If the overall GCD > 1, it's impossible to make any element 1
        # because gcd operations never introduce new prime factors.
        array_gcd = nums[0]
        for num in nums:
            array_gcd = gcd(array_gcd, num)
        if array_gcd > 1:
            return -1  # Impossible case

        # Step 2️⃣: If the array already contains 1s
        # Each existing 1 can help turn its neighbor into 1 with one operation.
        # So we need (n - number_of_ones) operations to make all elements 1.
        ones_count = nums.count(1)
        if ones_count > 0:
            return n - ones_count

        # Step 3️⃣: Find the smallest subarray whose GCD equals 1
        # This tells us the shortest "chain" we need to combine to create a single 1.
        min_subarray_length = n + 1  # Initialize with large number

        for start in range(n):
            current_gcd = nums[start]

            for end in range(start, n):
                current_gcd = gcd(current_gcd, nums[end])

                # Once we find a subarray with GCD == 1, record its length
                if current_gcd == 1:
                    min_subarray_length = min(min_subarray_length, end - start + 1)
                    break  # No need to extend further; GCD can’t get smaller than 1

        # Step 4️⃣: Calculate total operations
        # (min_subarray_length - 1): operations needed to turn that subarray into a single 1
        # (n - 1): operations needed to spread that 1 across the entire array
        #
        # Example: nums = [6,10,15]
        #   - Smallest subarray with gcd=1 is [6,10,15] (length = 3)
        #   - Takes (3 - 1) = 2 ops to make one '1'
        #   - Then (3 - 1) = 2 ops to spread that 1 → total 4
        return (min_subarray_length - 1) + (n - 1)

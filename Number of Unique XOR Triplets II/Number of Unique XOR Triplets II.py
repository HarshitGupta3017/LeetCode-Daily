# Solution for Number of Unique XOR Triplets II in PY

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)

        # Find the maximum value
        maximum_value = max(nums)

        # Smallest power of two greater than maximum_value
        xor_range = 1
        while xor_range <= maximum_value:
            xor_range <<= 1

        pair_xor_exists = [False] * xor_range
        triplet_xor_exists = [False] * xor_range

        # Generate all pair XORs
        for i in range(n):
            for j in range(i, n):
                pair_xor_exists[nums[i] ^ nums[j]] = True

        # Generate all triplet XORs
        for current_xor in range(xor_range):
            if not pair_xor_exists[current_xor]:
                continue

            for value in nums:
                triplet_xor_exists[current_xor ^ value] = True

        # Count distinct triplet XOR values
        return sum(triplet_xor_exists)

# Solution for Make Sum Divisible by P in PY

class Solution:
    def minSubarray(self, nums, p):
        n = len(nums)

        # total sum mod p
        total_mod_sum = sum(nums) % p

        if total_mod_sum == 0:
            return 0

        required_remainder = total_mod_sum % p

        prefix_mod_to_index = {0: -1}
        current_prefix_mod = 0
        min_length = n

        for j, num in enumerate(nums):
            current_prefix_mod = (current_prefix_mod + num) % p
            needed_mod = (current_prefix_mod - required_remainder) % p

            if needed_mod in prefix_mod_to_index:
                min_length = min(min_length, j - prefix_mod_to_index[needed_mod])

            prefix_mod_to_index[current_prefix_mod] = j

        return -1 if min_length == n else min_length

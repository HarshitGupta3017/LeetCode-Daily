# Solution for XOR After Range Multiplication Queries II in PY

MOD = 10**9 + 7

class Solution:

    # Fast exponentiation
    def power(self, base, exponent):
        if exponent == 0:
            return 1
        half = self.power(base, exponent // 2)
        result = (half * half) % MOD
        if exponent % 2 == 1:
            result = (result * base) % MOD
        return result

    def xorAfterQueries(self, nums, queries):
        n = len(nums)
        block_size = int(math.ceil(math.sqrt(n)))

        small_k_queries = defaultdict(list)

        # STEP 1: Large K
        for left, right, step, multiplier in queries:
            if step >= block_size:
                i = left
                while i <= right:
                    nums[i] = (nums[i] * multiplier) % MOD
                    i += step
            else:
                small_k_queries[step].append((left, right, multiplier))

        # STEP 2: Small K
        for step, qs in small_k_queries.items():
            diff = [1] * n

            for left, right, multiplier in qs:
                diff[left] = (diff[left] * multiplier) % MOD

                steps_count = (right - left) // step
                next_index = left + (steps_count + 1) * step

                if next_index < n:
                    inv = self.power(multiplier, MOD - 2)
                    diff[next_index] = (diff[next_index] * inv) % MOD

            for i in range(n):
                if i - step >= 0:
                    diff[i] = (diff[i] * diff[i - step]) % MOD

            for i in range(n):
                nums[i] = (nums[i] * diff[i]) % MOD

        # STEP 3: XOR
        final_xor = 0
        for val in nums:
            final_xor ^= val

        return final_xor

# Solution for Find Sum of Array Product of Magical Sequences in PY

class Solution:
    MOD = 10**9 + 7

    def mod_pow(self, a: int, b: int) -> int:
        result = 1
        while b > 0:
            if b & 1:
                result = (result * a) % self.MOD
            a = (a * a) % self.MOD
            b >>= 1
        return result

    def nCr(self, n: int, r: int, fact: list[int], inv_fact: list[int]) -> int:
        if r < 0 or r > n:
            return 0
        return ((fact[n] * inv_fact[r]) % self.MOD * inv_fact[n - r]) % self.MOD

    def dfs(self, binary_sum: int, idx: int, remaining: int, target_bits: int,
            nums: list[int], n: int, memo: dict, fact, inv_fact) -> int:
        
        # Base case
        if remaining == 0 and bin(binary_sum).count('1') == target_bits:
            return 1
        if remaining == 0 or idx >= n:
            return 0

        key = (binary_sum, idx, remaining, target_bits)
        if key in memo:
            return memo[key]

        total = 0

        # Skip current index
        total += self.dfs(binary_sum >> 1, idx + 1, remaining, target_bits - (binary_sum & 1),
                          nums, n, memo, fact, inv_fact)
        total %= self.MOD

        # Choose current index with frequency 1..remaining
        for freq in range(1, remaining + 1):
            new_sum = binary_sum + freq
            partial = self.dfs(new_sum >> 1, idx + 1, remaining - freq,
                               target_bits - (new_sum & 1), nums, n, memo, fact, inv_fact)
            partial = (partial * self.mod_pow(nums[idx], freq)) % self.MOD
            partial = (partial * self.nCr(remaining, freq, fact, inv_fact)) % self.MOD
            total = (total + partial) % self.MOD

        memo[key] = total
        return total

    def magicalSum(self, m: int, k: int, nums: list[int]) -> int:
        n = len(nums)

        # Precompute factorials and inverse factorials
        fact = [1] * (m + 1)
        inv_fact = [1] * (m + 1)
        for i in range(2, m + 1):
            fact[i] = (fact[i - 1] * i) % self.MOD
        for i in range(m + 1):
            inv_fact[i] = self.mod_pow(fact[i], self.MOD - 2)

        memo = {}
        return self.dfs(0, 0, m, k, nums, n, memo, fact, inv_fact) % self.MOD

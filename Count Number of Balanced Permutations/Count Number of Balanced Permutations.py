# Solution for Count Number of Balanced Permutations in PY

class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        MOD = 10**9 + 7
        n = len(num)
        totalDigitSum = sum(int(d) for d in num)
        if totalDigitSum % 2 == 1:
            return 0
        
        freq = [0] * 10
        for d in num:
            freq[int(d)] += 1

        # Precompute factorials and modular inverses
        fact = [1] * (n + 1)
        for i in range(2, n + 1):
            fact[i] = (fact[i - 1] * i) % MOD

        def mod_inv(x):
            return pow(x, MOD - 2, MOD)

        inv_fact = [1] * (n + 1)
        for i in range(n + 1):
            inv_fact[i] = mod_inv(fact[i])

        totalPermPossible = (fact[(n + 1) // 2] * fact[n // 2]) % MOD

        @lru_cache(maxsize=None)
        def solve(digit, evenIdxDigitsCount, currSum):
            if digit == 10:
                return totalPermPossible if currSum == totalDigitSum // 2 and evenIdxDigitsCount == (n + 1) // 2 else 0

            ways = 0
            maxEven = min(freq[digit], (n + 1) // 2 - evenIdxDigitsCount)
            for count in range(maxEven + 1):
                evenPosCount = count
                oddPosCount = freq[digit] - count
                div = (inv_fact[evenPosCount] * inv_fact[oddPosCount]) % MOD
                val = solve(digit + 1, evenIdxDigitsCount + evenPosCount, currSum + digit * count)
                ways = (ways + val * div) % MOD
            return ways

        return solve(0, 0, 0)

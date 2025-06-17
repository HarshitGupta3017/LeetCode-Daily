# Solution for Count the Number of Arrays with K Matching Adjacent Elements in PY

class Solution:
    MOD = 10**9 + 7

    def modPow(self, base: int, exp: int) -> int:
        result = 1
        base %= self.MOD
        while exp > 0:
            if exp % 2 == 1:
                result = (result * base) % self.MOD
            base = (base * base) % self.MOD
            exp //= 2
        return result

    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        fact = [1] * (n + 1)
        invFact = [1] * (n + 1)
        for i in range(2, n + 1):
            fact[i] = (fact[i - 1] * i) % self.MOD
        for i in range(n + 1):
            invFact[i] = self.modPow(fact[i], self.MOD - 2)

        equalPairsWays = (fact[n - 1] * invFact[k] % self.MOD) * invFact[n - k - 1] % self.MOD
        assignWays = m * self.modPow(m - 1, n - k - 1) % self.MOD
        return equalPairsWays * assignWays % self.MOD

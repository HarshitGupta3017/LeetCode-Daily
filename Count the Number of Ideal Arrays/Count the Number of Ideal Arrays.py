# Solution for Count the Number of Ideal Arrays in PY

class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = 10**9 + 7
        
        dp = [[0] * 15 for _ in range(maxValue + 1)]
        count = [0] * 15

        def findSets(m):
            if dp[m][1] != 0:
                return
            dp[m][1] = 1
            count[1] += 1
            for div in range(2, m + 1):
                if m % div == 0:
                    findSets(m // div)
                    for length in range(1, 14):
                        if dp[m // div][length] != 0:
                            dp[m][length + 1] += dp[m // div][length]
                            count[length + 1] += dp[m // div][length]

        def power(a, b):
            if b == 0:
                return 1
            half = power(a, b // 2)
            result = (half * half) % MOD
            if b % 2 == 1:
                result = (result * a) % MOD
            return result

        def modular_nCr(n, r, fact):
            if r < 0 or r > n:
                return 0
            a = fact[n]
            b = (fact[r] * fact[n - r]) % MOD
            return (a * power(b, MOD - 2)) % MOD

        for val in range(1, maxValue + 1):
            findSets(val)

        fact = [1] * (n + 1)
        for i in range(2, n + 1):
            fact[i] = (fact[i - 1] * i) % MOD

        result = 0
        for length in range(1, 15):
            if n < length:
                break
            if count[length] != 0:
                combinations = modular_nCr(n - 1, length - 1, fact)
                result = (result + (count[length] * combinations) % MOD) % MOD

        return result

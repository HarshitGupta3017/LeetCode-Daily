# Solution for Total Waviness of Numbers in Range I in PY

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0

        for n in range(num1, num2 + 1):
            if n < 100:
                continue

            d = []
            t = n
            while t:
                d.append(t % 10)
                t //= 10

            for i in range(1, len(d) - 1):
                l, c, r = d[i - 1], d[i], d[i + 1]
                if (c > l and c > r) or (c < l and c < r):
                    ans += 1

        return ans

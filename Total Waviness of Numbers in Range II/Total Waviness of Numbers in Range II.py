# Solution for Total Waviness of Numbers in Range II in PY

from functools import cache

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:

        def f(x):
            if x < 100:
                return 0

            s = str(x)

            @cache
            def dfs(i, pp, p, tight, lead):
                if i == len(s):
                    return 1, 0

                up = int(s[i]) if tight else 9
                cnt = wav = 0

                for d in range(up + 1):
                    nl = lead and d == 0
                    c, w = dfs(i + 1, p, -1 if nl else d,
                               tight and d == up, nl)

                    if not nl and pp >= 0 and p >= 0 and (
                        (pp < p > d) or (pp > p < d)
                    ):
                        wav += c

                    cnt += c
                    wav += w

                return cnt, wav

            return dfs(0, -1, -1, True, True)[1]

        return f(num2) - f(num1 - 1)

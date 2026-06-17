# Solution for Process String with Special Operations II in PY

class Solution:
    def processStr(self, s: str, k: int) -> str:
        n = 0

        for c in s:
            if c == '*':
                n -= n > 0
            elif c == '#':
                n *= 2
            elif c != '%':
                n += 1

        if k >= n:
            return '.'

        for c in reversed(s):
            if c == '*':
                n += 1
            elif c == '%':
                k = n - k - 1
            elif c == '#':
                n //= 2
                if k >= n:
                    k -= n
            else:
                n -= 1
                if k == n:
                    return c

        return '.'

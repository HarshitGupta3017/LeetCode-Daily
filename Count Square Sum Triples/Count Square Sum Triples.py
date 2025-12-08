# Solution for Count Square Sum Triples in PY

class Solution:
    def countTriples(self, n: int) -> int:
        result = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                c = int(math.sqrt(a * a + b * b))
                if (c <= n and c * c == a * a + b * b):
                    result += 1
        return result

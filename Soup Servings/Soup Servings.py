# Solution for Soup Servings in PY

class Solution:
    def soupServings(self, n: int) -> float:
        # For large n, the answer converges to 1.0
        if n >= 5000:
            return 1.0

        from functools import lru_cache

        @lru_cache(maxsize=None)
        def getProbability(a, b):
            # If both run out simultaneously
            if a <= 0 and b <= 0:
                return 0.5
            # If A runs out first
            if a <= 0:
                return 1.0
            # If B runs out first
            if b <= 0:
                return 0.0

            # Try all four serving options
            return 0.25 * (
                getProbability(a - 100, b) +
                getProbability(a - 75, b - 25) +
                getProbability(a - 50, b - 50) +
                getProbability(a - 25, b - 75)
            )

        return getProbability(n, n)

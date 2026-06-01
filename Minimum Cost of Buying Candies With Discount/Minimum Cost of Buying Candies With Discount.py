# Solution for Minimum Cost of Buying Candies With Discount in PY

class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        return sum(c for i, c in enumerate(sorted(cost, reverse=True)) if i % 3 != 2)

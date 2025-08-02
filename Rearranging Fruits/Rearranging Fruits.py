# Solution for Rearranging Fruits in PY

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        count_diff = Counter()
        min_fruit_cost = float('inf')

        for cost in basket1:
            count_diff[cost] += 1
            min_fruit_cost = min(min_fruit_cost, cost)

        for cost in basket2:
            count_diff[cost] -= 1
            min_fruit_cost = min(min_fruit_cost, cost)

        extra = []
        for fruit, diff in count_diff.items():
            if diff % 2 != 0:
                return -1
            extra.extend([fruit] * (abs(diff) // 2))

        extra.sort()
        swaps_needed = len(extra) // 2
        total_cost = 0

        for i in range(swaps_needed):
            total_cost += min(extra[i], 2 * min_fruit_cost)

        return total_cost

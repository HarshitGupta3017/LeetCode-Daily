# Solution for Maximum Fruits Harvested After at Most K Steps in PY

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        from bisect import bisect_left, bisect_right

        n = len(fruits)
        fruit_positions = [pos for pos, _ in fruits]
        cumulative_fruits = [0] * n
        cumulative_fruits[0] = fruits[0][1]

        for i in range(1, n):
            cumulative_fruits[i] = cumulative_fruits[i - 1] + fruits[i][1]

        max_collected = 0

        for detour in range(k // 2 + 1):
            # Case 1: left first, then right
            left_limit = startPos - detour
            right_limit = startPos + (k - 2 * detour)

            left_idx = bisect_left(fruit_positions, left_limit)
            right_idx = bisect_right(fruit_positions, right_limit) - 1

            if left_idx <= right_idx:
                total = cumulative_fruits[right_idx] - (cumulative_fruits[left_idx - 1] if left_idx > 0 else 0)
                max_collected = max(max_collected, total)

            # Case 2: right first, then left
            right_limit = startPos + detour
            left_limit = startPos - (k - 2 * detour)

            left_idx = bisect_left(fruit_positions, left_limit)
            right_idx = bisect_right(fruit_positions, right_limit) - 1

            if left_idx <= right_idx:
                total = cumulative_fruits[right_idx] - (cumulative_fruits[left_idx - 1] if left_idx > 0 else 0)
                max_collected = max(max_collected, total)

        return max_collected

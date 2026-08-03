# Solution for Stone Game III in PY

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        # dp[i+1], dp[i+2], dp[i+3]
        next_one = next_two = next_three = 0

        for i in range(n - 1, -1, -1):
            taken = stoneValue[i]

            # Take 1 stone
            best = taken - next_one

            # Take 2 stones
            if i + 2 <= n:
                taken += stoneValue[i + 1]
                best = max(best, taken - next_two)

            # Take 3 stones
            if i + 3 <= n:
                taken += stoneValue[i + 2]
                best = max(best, taken - next_three)

            # Shift the DP window
            next_three = next_two
            next_two = next_one
            next_one = best

        if next_one > 0:
            return "Alice"
        elif next_one < 0:
            return "Bob"
        return "Tie"

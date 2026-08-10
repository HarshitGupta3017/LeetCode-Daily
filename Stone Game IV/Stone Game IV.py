# Solution for Stone Game IV in PY

class Solution:
    # Returns True if the current player can guarantee a win
    # with exactly 'remaining' stones left.
    def solve(self, remaining, memo):
        # No stones left → current player loses.
        if remaining == 0:
            return False

        if memo[remaining] != -1:
            return memo[remaining] == 1

        # Try removing every perfect square <= remaining.
        k = 1
        while k * k <= remaining:
            if not self.solve(remaining - k * k, memo):
                memo[remaining] = 1
                return True
            k += 1

        # No winning move found.
        memo[remaining] = 0
        return False

    def winnerSquareGame(self, n):
        memo = [-1] * (n + 1)
        return self.solve(n, memo)

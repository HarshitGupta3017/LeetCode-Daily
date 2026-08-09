# Solution for Stone Game II in PY

class Solution:
    def stoneGameII(self, piles):
        n = len(piles)

        # memo[turn][idx][maxPiles]
        # turn = 1 -> Alice
        # turn = 0 -> Bob
        memo = [[[-1] * (n + 1) for _ in range(n)] for _ in range(2)]

        def solve(isAliceTurn, idx, maxPiles):
            if idx >= n:
                return 0

            turn = 1 if isAliceTurn else 0

            if memo[turn][idx][maxPiles] != -1:
                return memo[turn][idx][maxPiles]

            if isAliceTurn:
                best = float('-inf')
            else:
                best = float('inf')

            stonesSoFar = 0

            for x in range(1, min(2 * maxPiles, n - idx) + 1):
                stonesSoFar += piles[idx + x - 1]

                aliceFromHere = solve(
                    not isAliceTurn,
                    idx + x,
                    max(maxPiles, x)
                )

                if isAliceTurn:
                    best = max(best, stonesSoFar + aliceFromHere)
                else:
                    best = min(best, aliceFromHere)

            memo[turn][idx][maxPiles] = best
            return best

        return solve(True, 0, 1)

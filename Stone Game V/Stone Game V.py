# Solution for Stone Game V in PY

class Solution:
    # Returns the maximum score Alice can achieve from stoneValue[left..right].
    def solve(self, left, right, prefix, memo):
        if left >= right:
            return 0

        if memo[left][right] != -1:
            return memo[left][right]

        best_score = 0

        for mid in range(left, right):
            left_sum = prefix[mid] - (prefix[left - 1] if left > 0 else 0)
            right_sum = prefix[right] - prefix[mid]

            if left_sum < right_sum:
                # Keep left half.
                best_score = max(
                    best_score,
                    left_sum + self.solve(left, mid, prefix, memo)
                )

            elif right_sum < left_sum:
                # Keep right half.
                best_score = max(
                    best_score,
                    right_sum + self.solve(mid + 1, right, prefix, memo)
                )

            else:
                # Equal sums: choose the better continuation.
                keep_left = (
                    left_sum + self.solve(left, mid, prefix, memo)
                )

                keep_right = (
                    right_sum + self.solve(mid + 1, right, prefix, memo)
                )

                best_score = max(
                    best_score,
                    keep_left,
                    keep_right
                )

        memo[left][right] = best_score
        return best_score

    def stoneGameV(self, stoneValue):
        n = len(stoneValue)

        # Prefix sums.
        prefix = [0] * n
        prefix[0] = stoneValue[0]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + stoneValue[i]

        # Memo table initialized with -1.
        memo = [[-1] * n for _ in range(n)]

        return self.solve(0, n - 1, prefix, memo)

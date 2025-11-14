# Solution for Increment Submatrices by One in PY

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:

        # 🔹 2D difference matrix
        diff = [[0] * n for _ in range(n)]

        # 🔹 Apply difference updates for each query
        for r1, c1, r2, c2 in queries:

            for row in range(r1, r2 + 1):

                # Start +1 influence
                diff[row][c1] += 1

                # End +1 influence
                if c2 + 1 < n:
                    diff[row][c2 + 1] -= 1

        # 🔹 Convert each row to prefix sums
        for row in range(n):
            for col in range(1, n):
                diff[row][col] += diff[row][col - 1]

        return diff

# Solution for Number of Paths with Max Score in PY

class Solution:
    MOD = 10**9 + 7

    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)

        @lru_cache(None)
        def solve(i, j):
            if board[i][j] == 'E':
                return (0, 1)
            if board[i][j] == 'X':
                return (0, 0)

            best_score = best_paths = 0

            for ni, nj in ((i - 1, j), (i, j - 1), (i - 1, j - 1)):
                if 0 <= ni < n and 0 <= nj < n and board[ni][nj] != 'X':
                    score, paths = solve(ni, nj)
                    if paths:
                        score += 0 if board[i][j] == 'S' else int(board[i][j])

                    if score > best_score:
                        best_score, best_paths = score, paths
                    elif score == best_score and paths:
                        best_paths = (best_paths + paths) % self.MOD

            if best_paths == 0:
                best_score = 0

            return (best_score, best_paths)

        return list(solve(n - 1, n - 1))

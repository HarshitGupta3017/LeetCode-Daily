# Solution for Snakes and Ladders in PY

class Solution:
    def getCoordinates(self, squareNumber: int, boardSize: int) -> List[int]:
        rowFromTop = (squareNumber - 1) // boardSize
        rowFromBottom = (boardSize - 1) - rowFromTop
        col = (squareNumber - 1) % boardSize

        if rowFromBottom % 2 == boardSize % 2:
            col = (boardSize - 1) - col

        return [rowFromBottom, col]

    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        bfsQueue = deque([1])

        visited = [[False] * n for _ in range(n)]
        visited[n - 1][0] = True

        moves = 0

        while bfsQueue:
            levelSize = len(bfsQueue)

            for _ in range(levelSize):
                currentSquare = bfsQueue.popleft()

                if currentSquare == n * n:
                    return moves

                for dice in range(1, 7):
                    nextSquare = currentSquare + dice
                    if nextSquare > n * n:
                        break

                    row, col = self.getCoordinates(nextSquare, n)

                    if visited[row][col]:
                        continue

                    visited[row][col] = True

                    destination = board[row][col] if board[row][col] != -1 else nextSquare
                    bfsQueue.append(destination)

            moves += 1

        return -1

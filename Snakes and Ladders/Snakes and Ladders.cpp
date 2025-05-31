// Solution for Snakes and Ladders in CPP

class Solution {
public:

    // Converts square number to its row and column index on the board considering Boustrophedon layout
    pair<int, int> getCoordinates(int squareNumber, int boardSize) {
        int rowFromTop = (squareNumber - 1) / boardSize;
        int rowFromBottom = (boardSize - 1) - rowFromTop;

        int col = (squareNumber - 1) % boardSize;

        // Reverse column direction on every alternate row (right-to-left)
        if (rowFromBottom % 2 == boardSize % 2) {
            col = (boardSize - 1) - col;
        }

        return make_pair(rowFromBottom, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();  // Board size (n x n)

        queue<int> bfsQueue;   // BFS queue to store current square positions
        bfsQueue.push(1);      // Start from square 1

        // Track visited positions to avoid cycles
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n - 1][0] = true;  // Mark square 1 as visited

        int moves = 0;  // Count number of dice rolls

        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();  // Number of positions to explore at current move

            while (levelSize--) {
                int currentSquare = bfsQueue.front();
                bfsQueue.pop();

                // If we've reached the final square
                if (currentSquare == n * n) return moves;

                // Simulate dice rolls (1 to 6)
                for (int dice = 1; dice <= 6; dice++) {
                    int nextSquare = currentSquare + dice;
                    if (nextSquare > n * n) break;  // Cannot move beyond the last square

                    pair<int, int> coords = getCoordinates(nextSquare, n);
                    int row = coords.first;
                    int col = coords.second;

                    if (visited[row][col]) continue;

                    visited[row][col] = true;

                    // If there's a snake or ladder, move to its destination
                    int destination = board[row][col] == -1 ? nextSquare : board[row][col];
                    bfsQueue.push(destination);
                }
            }

            moves++;  // Increment number of moves (dice rolls)
        }

        // If it's not possible to reach the final square
        return -1;
    }
};

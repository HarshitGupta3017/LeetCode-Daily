// Solution for Snakes and Ladders in JAVA

class Solution {

    private int[] getCoordinates(int squareNumber, int boardSize) {
        int rowFromTop = (squareNumber - 1) / boardSize;
        int rowFromBottom = (boardSize - 1) - rowFromTop;
        int col = (squareNumber - 1) % boardSize;

        if (rowFromBottom % 2 == boardSize % 2) {
            col = (boardSize - 1) - col;
        }

        return new int[]{rowFromBottom, col};
    }

    public int snakesAndLadders(int[][] board) {
        int n = board.length;

        Queue<Integer> bfsQueue = new LinkedList<>();
        bfsQueue.add(1);

        boolean[][] visited = new boolean[n][n];
        visited[n - 1][0] = true;

        int moves = 0;

        while (!bfsQueue.isEmpty()) {
            int levelSize = bfsQueue.size();

            while (levelSize-- > 0) {
                int currentSquare = bfsQueue.poll();

                if (currentSquare == n * n) return moves;

                for (int dice = 1; dice <= 6; dice++) {
                    int nextSquare = currentSquare + dice;
                    if (nextSquare > n * n) break;

                    int[] coords = getCoordinates(nextSquare, n);
                    int row = coords[0];
                    int col = coords[1];

                    if (visited[row][col]) continue;

                    visited[row][col] = true;

                    int destination = board[row][col] == -1 ? nextSquare : board[row][col];
                    bfsQueue.add(destination);
                }
            }

            moves++;
        }

        return -1;
    }
}

// Solution for Design Spreadsheet in JAVA

class Spreadsheet {
    int[][] grid;

    public Spreadsheet(int rows) {
        grid = new int[rows][26];
    }

    private int[] parseCell(String cell) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;
        return new int[]{row, col};
    }

    public void setCell(String cell, int value) {
        int[] pos = parseCell(cell);
        grid[pos[0]][pos[1]] = value;
    }

    public void resetCell(String cell) {
        int[] pos = parseCell(cell);
        grid[pos[0]][pos[1]] = 0;
    }

    private int evaluate(String token) {
        if (Character.isDigit(token.charAt(0))) return Integer.parseInt(token);
        int[] pos = parseCell(token);
        return grid[pos[0]][pos[1]];
    }

    public int getValue(String formula) {
        String expr = formula.substring(1);
        String[] parts = expr.split("\\+");
        return evaluate(parts[0]) + evaluate(parts[1]);
    }
}

# Solution for Design Spreadsheet in PY

class Spreadsheet:
    def __init__(self, rows: int):
        self.grid = [[0] * 26 for _ in range(rows)]

    def parseCell(self, cell: str):
        col = ord(cell[0]) - ord('A')
        row = int(cell[1:]) - 1
        return row, col

    def setCell(self, cell: str, value: int):
        r, c = self.parseCell(cell)
        self.grid[r][c] = value

    def resetCell(self, cell: str):
        r, c = self.parseCell(cell)
        self.grid[r][c] = 0

    def evaluate(self, token: str):
        if token[0].isdigit():
            return int(token)
        r, c = self.parseCell(token)
        return self.grid[r][c]

    def getValue(self, formula: str):
        left, right = formula[1:].split("+")
        return self.evaluate(left) + self.evaluate(right)

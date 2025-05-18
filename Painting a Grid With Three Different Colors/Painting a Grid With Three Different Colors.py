# Solution for Painting a Grid With Three Different Colors in PY

class Solution:

    def __init__(self):
        self.columnStates = []
        self.MOD = 10**9 + 7
        self.dp = []

    def generateColumnStates(self, curr: str, prevChar: str, l: int, m: int):
        if l == m:
            self.columnStates.append(curr)
            return
        for currColor in {'R', 'G', 'B'}:
            if currColor == prevChar:
                continue
            self.generateColumnStates(curr + currColor, currColor, l + 1, m)

    def solve(self, remainCols: int, prevIdx: int, m: int) -> int:
        if remainCols == 0:
            return 1
        if self.dp[remainCols][prevIdx] != -1:
            return self.dp[remainCols][prevIdx]
        ways = 0
        prevState = self.columnStates[prevIdx]
        for i in range(len(self.columnStates)):
            if i == prevIdx:
                continue
            currState = self.columnStates[i]
            valid = all(prevState[j] != currState[j] for j in range(m))
            # valid = True
            # for j in range(m):
            #     if prevState[j] == currState[j]:
            #         valid = False
            if valid:
                ways = (ways + self.solve(remainCols - 1, i, m)) % self.MOD
        self.dp[remainCols][prevIdx] = ways
        return ways

    def colorTheGrid(self, m: int, n: int) -> int:
        self.generateColumnStates("", '#', 0, m)
        totalStates = len(self.columnStates)
        self.dp = [[-1] * (totalStates + 1) for _ in range(n + 1)]
        result = 0
        for i in range(totalStates):
            result = (result + self.solve(n - 1, i, m)) % self.MOD
        return result

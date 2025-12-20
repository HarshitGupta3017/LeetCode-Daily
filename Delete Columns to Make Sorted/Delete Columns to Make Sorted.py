# Solution for Delete Columns to Make Sorted in PY

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        numRows = len(strs)
        numCols = len(strs[0])
        columnsToDelete = 0

        for col in range(numCols):
            for row in range(1, numRows):
                if strs[row][col] < strs[row - 1][col]:
                    columnsToDelete += 1
                    break

        return columnsToDelete

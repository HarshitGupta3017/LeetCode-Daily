# Solution for Count Submatrices With All Ones in PY

class Solution:
    def countOnes(self, arr):
        ones, total = 0, 0
        for v in arr:
            if v == 0:
                ones = 0
            else:
                ones += 1
            total += ones
        return total

    def numSubmat(self, mat: List[List[int]]) -> int:
        rows, cols = len(mat), len(mat[0])
        total = 0
        for i in range(rows):
            mask = [1] * cols
            for j in range(i, rows):
                for k in range(cols):
                    mask[k] &= mat[j][k]
                total += self.countOnes(mask)
        return total

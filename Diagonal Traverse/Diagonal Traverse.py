# Solution for Diagonal Traverse in PY

class Solution:
    def findDiagonalOrder(self, mat):
        rows, cols = len(mat), len(mat[0])
        
        # Dictionary to group elements by the sum of indices (i + j)
        diagonal_map = defaultdict(list)
        
        for row in range(rows):
            for col in range(cols):
                diagonal_key = row + col
                diagonal_map[diagonal_key].append(mat[row][col])
        
        result = []
        reverse_flag = True  # Used to alternate reversing of diagonals
        
        # Process diagonals in order of their keys (0, 1, 2, ...)
        for key in range(0, rows + cols + 1):
            diagonal = diagonal_map[key]
            
            # Reverse every alternate diagonal
            if reverse_flag:
                diagonal.reverse()
            
            # Append diagonal elements to result
            result.extend(diagonal)
            
            # Alternate the reverse flag for the next diagonal
            reverse_flag = not reverse_flag
        
        return result
